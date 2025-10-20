import os

# Root docs folder
DOCS_DIR = "docs"
OUTPUT_FILE = "nav.yml"

def make_nav():
    nav_lines = ["- Home: index.md", "- Reference:"]
    ref_dir = os.path.join(DOCS_DIR, "reference")
    for lang in sorted(os.listdir(ref_dir)):
        lang_path = os.path.join(ref_dir, lang)
        if os.path.isdir(lang_path):
            nav_lines.append(f"  - {lang.capitalize()}:")
            # list markdown files
            md_files = sorted(f for f in os.listdir(lang_path) if f.endswith(".md"))
            for md in md_files:
                if md == "index.md":
                    nav_lines.append(f"    - '{lang.capitalize()} Overview': reference/{lang}/index.md")
                else:
                    title = os.path.splitext(md)[0].replace("_", " ").capitalize()
                    nav_lines.append(f"    - '{title}': reference/{lang}/{md}")
    return "\n".join(nav_lines)

with open(OUTPUT_FILE, "w") as f:
    f.write(make_nav())