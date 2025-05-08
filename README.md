# basic_programming
## Getting Started
### Windows
- VSCode
    - https://code.visualstudio.com/download
- Git
    - https://git-scm.com/downloads/win
- WSL
    - Powershell: Run as administrator
    - `wsl --install`
    - Requires restart
### Linux
- VSCode
    - https://code.visualstudio.com/download
- Git
    - Most likely already installed
    - `sudo apt install git`
- Mingw-w64
    - `sudo apt-get install mingw-w64`
## Using Git
### Clone this Repo
- Suggest navigating to a `src` directory
    - ex: `/home/student/src`
    - ex: `C:\Users\student\src`
- `git clone https://github.com/yakra13/basic_programming.git`

### Create A Branch
- Terminal
    - `cd basic_programming`
    - `git branch`
        - Lists your local branches and your active branch
        - If you are not on main use: `git checkout main`
    - `git pull`
        - Make sure your main branch is up-to-date
    - `git checkout -b my-branch-name`
        - Create your new branch and switch to it
        - Name your branch something unique: `your-call-sign-working`
- VSCode
    - `File` > `Open Folder...` > Navigate to `basic_programming`
    - Bottom left of the window you should see `main*`
    - Click on it then select `Create new branch from...`
    - Select `main` or `origin/main`
        - `main` is your local branch
            - Make sure it is up-to-date, incoming changes will be marked in the lower left next to the branch name. Click it to pull the changes.
        - `origin/main` is the remote branch
    - Provide a branch name and hit enter
        - Name your branch something unique: `your-call-sign-working`
### Push Your Changes
- Terminal
    - `git status`
        - Show local changes, etc.
    - `git add .`
        - Stage all changes, or specify individual files
    - `git commit -m "Enter commit message here."`
    - `git push`
- VSCode
    - Select the source control tab on the left bar (Ctrl+Shift+G by default)
    - Enter a commit message
    - Select the files to stage and stage them wit the + symbol
        - Stage all changes with + revealed when hovering over `Changes`
    - Click Commit
    - Click Sync Changes
- **Note:** Empty folders will not be pushed. You can add an empty placeholder file if you need the folders to be pushed.

### .gitignore File
- Used to ignore files that you do not want to include in the remote branch. They will remain only in your local branch.
- Each file or pattern is placed on a new line.
- Example `.gitignore` file stored at the source root
```
# This is a comment
*.exe        # Ignore all exe files
*.tmp        # Ignore all tmp files

build/       # Ignore the entire build directory

logs/*       # Ignore the contents of logs directory but not the directory itself
!/logs/.keep # Do not ignore .keep file in logs directory

secrets.txt  # Ignore a specific file
```