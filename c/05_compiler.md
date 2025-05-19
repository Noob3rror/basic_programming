# Compiler
## gcc
We'll describe how the compiler creates our program using `gcc` with our vector program in `c\src\vector\`.

## Inspecting the Stages
There are a few stages we can directly look at during the compilation process.
### Preprocessor
The preprocessor happens before Lexical Analysis. Removes comments, resolves macros (`#define`) and expands `#include` directives.
```
gcc -E main.c -o main.i
```
- View `main.i` in VSCode
### Compilation
We can now produce the assembly output of our code. Lexical analysis thru target code generation occurs here.
```
gcc -S main.i -o main.s
```
You can also compile directly from the C source to assembly:
```
gcc -S main.c -o main.s
```
- View `main.s` in VSCode
### Assembly
Assemble the .s file into an object file (.o):
```
gcc -c main.s -o main.o
```
Or from C directly:
```
gcc -c main.c -o main.o
```
- View `main.o` with:
    - `objdump -d main.o`
- Lets also build `vector.c` here
```
gcc -c vector.c -o vector.o
```
### Linking
Link the object file to produce the executable:
```
gcc main.o vector.o -o main
```
- Run the resulting program
```
./main
```
- And lets dump it to see how the object files were linked.
    - `objdump -d main`
## GCC Flags
See [GCC](./compiling.md#gcc)
