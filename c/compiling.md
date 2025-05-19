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
- Lexical Analysis (Lexer/Tokenizer)
    - Breaks the source code into tokens
        - `int x = 5;` → `int`, `x`, `=`, `5`, `;`
- Syntax Analysis (Parser)
    - Builds a syntax tree from the tokens
    - Checks for grammar correctness.
- Semantic Analysis
    - Validate meaning: type checking, scope rules, function declarations.
- Intermediate Code Generation
    - Converts the syntax tree to lower-level intermediate representation.
        - GIMPLE or RTL for `gcc`
- Optimization
    - Code optimizations such as removing dead code, loop unrolling, etc.
- Target Code Generation
    - Converts to assembly (ie x86_64 instructions)
- Assembling
    - Generates object code (machine instructions) from the assembly.
- Linking
    - Combines object files and resolves symbols for the final executable.
### Preprocessor
The preprocessor happens before Lexical Analysis. Removes comments, resolves macros (`#define`) and expands `#include` directives.
```
gcc -E main.c -o main.i
```
### Compilation
We can now produce the assembly output of our code. Lexical analysis thru target code generation occurs here.
```
gcc -S main.i -o main.s
```
You can also compile directly from the C source to assembly:
```
gcc -S main.c -o main.s
```
### Assembly
Assemble the .s file into an object file (.o):
```
gcc -c main.s -o main.o
```
Or from C directly:
```
gcc -c main.c -o main.o
```
### Linking
Link the object file to produce the executable:
```
gcc main.o vector.o -o main
```

TODO
>Static vs dynamic linking (.a vs .so / .lib vs .dll).
>Using linker flags like -L, -l, and -Wl.
#### Static
TODO
#### Dynamic
TODO
## Windows
### msvc
TODO

Explain using the cl.exe compiler.
Discuss using the Developer Command Prompt.
Show how to compile from the command line and through Visual Studio.
Cover .vcxproj files and how they interact with build settings.
Flags etc
### mingw
TODO

Describe installing MinGW and setting up environment variables.
Show command-line examples using gcc under MinGW.
Mention compatibility with POSIX-like tools (e.g., make, bash).
Flags etc
## Linux
### gcc
#### Compilation Stages
|Flag|Description|
|-|-|
|`-c`|Compile only; do not link. Produces .o (object) files.|
|`-S`|Compile to assembly code (produces .s files).|
|`-E`|Preprocess only; output is raw source after macros/includes.|
|`-o <file>`|Set output file name.|

#### Warnings and Errors
|Flag|Description|
|-|-|
|`-Wall`|Enable most common warnings.|
|`-Wextra`|Enable additional useful warnings.|
|`-Werror`|Treat all warnings as errors.|
|`-pedantic`|Enforce strict ANSI C compliance.|
|`-Wshadow`|Warn when a variable declaration shadows another.|

#### Debugging
|Flag|Description|
|-|-|
|`-g`|Include debug information (for gdb and other debuggers).|

#### Optimization
|Flag|Description|
|-|-|
|`-O0`|No optimization (default when debugging).|
|`-O1`, `-O2`, `-O3`|Increasing levels of optimization.|
|`-Os`|Optimize for size.|
|`-Ofast`|Aggressive optimizations, may break strict standards.|

#### Linking
|Flag|Description|
|-|-|
|`-l<lib>`|Link with library (e.g., `-lm` for math)|
|`-L<dir>`|Add directory to library search path|
|`-static`|Link statically (no dynamic/shared libs)|
|`-shared`|Create a shared library|

#### Standards and Compatibility
|Flag|Description|
|-|-|
|`-std=c99`, `-std=c11`, `-std=gnu99`|Specify language standard.|
|`-ansi`|Strict ANSI C.|
|`-m32` / `-m64`|Compile for 32-bit or 64-bit architecture.|

#### Security / Hardening
|Flag|Description|
|-|-|
|`-fstack-protector`|Enable stack canaries for buffer overflow detection.|
|`-fPIE` / `-pie`|Enable Position-Independent Executables (ASLR support).|
|`-D_FORTIFY_SOURCE=2`|Enable extra compile-time checks on functions like `strcpy()`.

#### Miscellaneous
|Flag|Description|
|-|-|
|`-I<dir>`|Add include directory for headers.|
|`-D<macro>`|Define a macro (e.g., `-DDEBUG`).|
|`-fPIC`|Generate Position Independent Code (for shared libraries).|
## Automation
### make
TODO

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