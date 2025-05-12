TODO

- [Compiling](#compiling)
    - [Stages](#stages)
        - [Preprocessing](#preprocessing)
        - [Compilation](#compilation)
        - [Assembly](#assembly)
        - [Linking](#linking)
            - [Static](#static)
            - [Dynamic](#dynamic)
    - [Windows](#windows)
        - [msvc](#msvc)
        - [mingw](#mingw)
    - [Linux](#linux)
        - [gcc](#gcc)
    - [Automation](#automation)
        - [make](#make)
        - [bash](#bash)
        - [vscode](#vscode)
- [Cross Compiling](#cross-compiling)
# Compiling
## Stages
### Preprocessing
Role of the preprocessor (#include, #define, #ifdef).
How macros influence code generation.
### Compilation
### Assembly
### Linking
Static vs dynamic linking (.a vs .so / .lib vs .dll).
Using linker flags like -L, -l, and -Wl.
#### Static
...
#### Dynamic
...
## Windows
### msvc
Explain using the cl.exe compiler.
Discuss using the Developer Command Prompt.
Show how to compile from the command line and through Visual Studio.
Cover .vcxproj files and how they interact with build settings.
Flags etc
### mingw
Describe installing MinGW and setting up environment variables.
Show command-line examples using gcc under MinGW.
Mention compatibility with POSIX-like tools (e.g., make, bash).
Flags etc
## Linux
### gcc
Explain the basic usage of gcc with flags like -Wall, -o, -g, -O2.
Touch on common GCC extensions or options like -std=c99, -pedantic.
Discuss linking multiple files, and static vs shared libraries.
Flags like -g, -O0, -O2, -O3, and -DNDEBUG.
Explain trade-offs between debug and release builds
## Automation
### make
Introduction to Makefile syntax.
Explain rules, dependencies, and phony targets.
Show examples of compiling multi-file projects.
### bash
Use of shell scripts to wrap compilation logic.
Examples of conditionally compiling with arguments or checks.
### vscode
...
# Cross Compiling
Explain building binaries for a platform other than the host (e.g., compiling for ARM on x86).
Mention tools like x86_64-w64-mingw32-gcc or arm-linux-gnueabi-gcc.
Describe configuration of toolchains and triplets.



1. Preprocessing, Compilation, Assembly, Linking

Explain the stages of the compilation process:

    Preprocessing (cpp): Handles #include, #define, and macros.

    Compilation (cc): Converts preprocessed code to assembly.

    Assembly (as): Converts assembly to machine code (object files).

    Linking (ld): Combines object files into a single executable.

2. Optimization

Discuss compiler optimization flags:

    -O0, -O1, -O2, -O3, -Os, -Ofast for GCC/Clang.

    /Od, /O2, /Ox for MSVC.
    Explain trade-offs: size vs. speed, and potential debugging difficulties.

3. Debugging Symbols

Explain options to include symbols for debugging:

    GCC: -g

    MSVC: /Zi, /Fd

    Importance for tools like gdb, lldb, and Visual Studio Debugger.

4. Static vs Dynamic Linking

Cover:

    What static (.lib, .a) and dynamic (.dll, .so) libraries are.

    Pros/cons and how to link each type with GCC/MSVC.

5. Common Compiler Flags

Create a table or list of common flags:

    -Wall, -Wextra, -pedantic, /W4, /WX, etc.

    -I, -L, -l for include paths, library paths, and linking libs.

6. Platform-Specific Tips

    Linux: pkg-config, ldd, strace

    Windows: Setting up PATH, Visual Studio Developer Command Prompt

7. Tools for Cross Compilation

    x86_64-w64-mingw32-gcc for Linux → Windows

    ARM toolchains: arm-none-eabi-gcc, etc.

8. CI/CD Integration

Explain how builds are automated in pipelines:

    GitHub Actions, GitLab CI, Jenkins

    Example build scripts for C projects