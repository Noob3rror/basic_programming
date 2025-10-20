# Files
## C Files
A `c` file typically contains the **implementation** of a program. Definitions of functions and globals of a `.h` or acts as the entry point of a program (usually named `main.c`). `.c` files are compiled into object (`.o`) files and linked together to produce an executable (`.exe`, `.elf`), library (`.dll`, `.so`) file.

C files are processed from top to bottom which means the order you declare, define and use functions, variables etc matters.
### C File Common Components
#### `#include` Statements
- Include various header files to access their function and variable definitions.
    - ie `<stdio.h>` or standard input/output which contains functions like `printf()`.
- Included files are effectively copied and pasted into the current file.
```c
#include <stdio.h> // Includes functions related to input/output such as printing characters to a terminal.
```
#### Function Definitions
- Actual code implementations of functions **declared** in accompanying `.h` files.
    - Functions can be declared in `.c` files as well. These are function prototypes.
- From top to bottom functions must be defined **or** declared before they are used.
```c
long factorial(long n); // A function prototype

// The function definition/implementation
long factorial(long n)
{
    // Check for invalid input
    if (n < 0)
        return -1;

    long result = 1;

    for (; n > 1; --n)
    {
        result *= n;
    }

    return result;
}
```
#### Main Entry Point
- Only one allowed in a program.
- Marks where the program begins execution.
    - The true beginning of execution is outside of you `main()` function but that is rarely relevant for writing code.
```c
int main(void)
{
    // Code ...
    return 0;
}
```
#### Internal Functions
- Functions that only exist within this `.c` file.
- These functions are inaccessible outside of the file they are defined in.
- Often marked `static` but not required.
```c
static void helper_func(int)
{
    // Implementation ...
}
```
### C Sample
```c
// Standard library includes
#include <stdio.h>

// Third party includes
#include "third-party-library.h"

// Internal includes
#include "mylibrary.h"

// Defines
#define MY_SPECIFIC_VALUE 22

// Forward declarations
void my_func(int a, int b);

// Program entry point typically in 'main.c'
int main(int argc, char* argv[])
{
    my_func(1, 2); // This function 'sees' my_func due to the forward declaration above.
    return 0;
}

// If this was defined above main() the forward declaration could be omitted
void my_func(int a, int b)
{
    printf("a + b = %d", a + b);
}
```
## Header Files
A header file is a file with a `.h` (or `.hpp` for C++) extension that contains declarations that can be shared with `.c` files. It allows for code reuse and organization, separating **declarations** from **definitions**.
### H File Common Components
#### Function Declarations (Prototypes)
- `void my_function(int);`
- Declares a function allowing `.c` files that `#include` the header file to 'see' a function is available.
- The function must of course be **defined** somewhere and **linked** at compile time.
#### Macro Definitions
- `#define MAX_BUFFER_SIZE 1024`
- Used for constants or even code snippets.
#### Type Definitions
- `typedef unsigned int uint;`
- Used to create aliases. In this example `uint` becomes an alias of `unsigned int`.
#### Structure and Enum Declarations
- Make available data structures and enumerations.

```c 
typedef struct
{
    int id;
    char name[50];
} User;
```
#### Global Variable Declarations (extern)
- `extern int global_count;`
- `extern` variables are only declared in `.h` files and must be **defined** elsewhere.
#### Include Guards
- Include guards prevent double-inclusion which can cause errors.
- Header files should **always** have include guards and the label (`MYHEADER_H`) must be unique.
- A good format is project name + header name + H
    - ex `MY_PROJECT_VECTOR_H` for a math vector library part of your project.
```c
#ifndef MYHEADER_H
#define MYHEADER_H
// ...
#endif
```
- Optionally many compilers support `#pragma once` as an alternate to include guards.
- Using `#pragma once` is certainly simpler as you do not need to come up with unique names but be careful if portability is a concern.
### Header Sample
```c
// Include guard
#ifndef MY_UNIQUE_IDENTIFIER_H
#define MY_UNIQUE_IDENTIFIER_H
// Any required includes
#include <stdint.h>

// Any defines/macros to be made available wherever this .h file is included
#define SOME_CONSTANT_VALUE 443 // such as a specific port number, etc

// Global declarations
extern uint8_t my_global;

// Type definitions
typedef struct
{
    int x;
    int y;
    char* ptr_name;
} CustomDataStructure;

// Forward declarations
void my_func(float, char*); // Defined in .c file

// Function definitions
// Typically functions are defined in .c files but can be defined in h files for specific purposes such as header only libraries
void my_header_only_func(int value)
{
    // Code
}

#endif
```
## Object Files
TODO