// Helper functions for cookies
function setCookie(name, value, days = 365) {
    const d = new Date();
    d.setTime(d.getTime() + days*24*60*60*1000);
    document.cookie = name + "=" + encodeURIComponent(value) + ";path=/;expires=" + d.toUTCString();
}

function getCookie(name) {
    const value = `; ${document.cookie}`;
    const parts = value.split(`; ${name}=`);
    if (parts.length === 2) return decodeURIComponent(parts.pop().split(';').shift());
    return null;
}
// Check answers and highlight correct/incorrect
function checkQuiz(btn, quizId) {
    const container = btn.closest(".quiz");
    const results = container.querySelector(".quiz-result");
    const inputs = container.querySelectorAll("input");

    let totalCorrect = 0;
    let totalOptions = 0;
    let allCorrect = true;

    inputs.forEach(input => {
        const isCorrect = input.dataset.correct === "true";
        const isChecked = input.checked;

        totalOptions++;
        if ((isCorrect && !isChecked) || (!isCorrect && isChecked)) {
            allCorrect = false;
        }

        // Remove previous highlights
        input.parentElement.classList.remove("correct", "incorrect");

        // Apply highlight if selected or correct
        if (isChecked) {
            input.parentElement.classList.add(isCorrect ? "correct" : "incorrect");
        }
    });

    results.textContent = allCorrect ? "Correct!" : "Incorrect";
    
    // Save progress in cookies
    if (quizId) {
        setCookie("mcq_" + quizId, allCorrect ? "100" : "0");
    }
}

// Restore saved progress
document.addEventListener("DOMContentLoaded", () => {
    document.querySelectorAll(".quiz").forEach(container => {
        const quizId = container.dataset.quizId;
        if (quizId) {
            const saved = getCookie("mcq_" + quizId);
            if (saved) {
                const results = container.querySelector(".quiz-result");
                results.textContent = `Previous score: ${saved}%`;
            }
        }
    });
});

async function renderQuestionById(jsonPath, questionId, containerId) {
    console.log("Rendering question", questionId, "from", jsonPath);
    const container = document.getElementById(containerId);
    container.innerHTML = ""; // clear any existing content

    const response = await fetch(jsonPath);
    const questions = await response.json();

    // Find the question with the requested ID
    const q = questions.find(q => q.id === questionId);
    if (!q) {
        container.innerHTML = "<p>Question not found.</p>";
        return;
    }

    const qDiv = document.createElement("div");
    qDiv.className = "quiz";
    qDiv.dataset.quizId = q.id;

    let html = `<p>${q.question}</p>`;
    q.options.forEach(opt => {
        const inputType = q.type === "single" ? "radio" : "checkbox";
        html += `<label><input type="${inputType}" name="${q.id}" data-correct="${opt.correct}"> ${opt.text}</label><br>`;
    });

    html += `<button class="md-button md-raised md-primary" onclick="checkQuiz(this,'${q.id}')">Check</button>`;
    html += `<p class="quiz-result"></p>`;
    qDiv.innerHTML = html;

    container.appendChild(qDiv);
}