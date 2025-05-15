
## Header Overview
A header file is a file with a `.h` (or `.hpp` for C++) extension that contains declarations that can be shared with `.c` files. It allows for code reuse and organization, separating **declarations** from **definitions**.

See [files.md](./files.md)

## Vector Math Library
We will create a library of common vector functions. In this case vector meaning the geometric object that possesses a magnitude and direction. (In C++ the term vector is also used for a list/dynamically sized array).

- Create a new folder `c/src/vector` and create two files: `vector.h` and `vector.c`
- Inside of `vector.h` lets start with *include guards*
    - See [Include Guards](./files.md#include-guards)
```c
#ifndef TRNG_VECTOR_H // check if 'TRNG_VECTOR_H' is already defined
#define TRNG_VECTOR_H // if not then we define it

// Code here...

#endif // Don't forget your endif and place your code between the ifndef and endif
```
- A vector can be considered a *complex* data type. So we can use a `struct` to package together some standard types to represent a vector.
    - We will create what is commonly called a `vector2` or 2-dimensional vector.
    - We will typedef our struct to make it more readable
        - See [Type Aliasing](./types.md#type-aliasing)
```c
#ifndef TRNG_VECTOR_H
#define TRNG_VECTOR_H

typedef struct _vector2 // In most compilers you can omit `_vector2` when typedef-ing a struct
{
    double x, y; // We can declare multiple variables of the same type using a , separator
} Vector2;

#endif
```
- Next lets declare two function prototypes for working with vectors: `vec2_add()` and `vec2_sub()`
```c
...
    double x, y;
} Vector2;

Vector2 vec2_add(Vector2 v1, Vector2 v2);
Vector2 vec2_sub(Vector2 v1, Vector2 v2);

#endif
```
- We are done with our header file for now so lets open `vector.c` and implement our functions.
- The first thing we need to do in `vector.c` is to let this file know about our vector struct and functions we declared in our header.
```c
#include "vector.h"
```
- Notice we used `" "` instead of `< >` around `vector.h`. `< >` are used for system/standard library headers (`<stdio.h>`, `<stdlib.h>`, `<string.h>`) and lets the compiler know to search for the headers in system directories like `/usr/include/`. `" "` are used for our own headers and makes the compiler search the current directory (location of the source file) then use system paths/include paths.
- Implement the `vec2_add()` function.
```c
#include "vector.h"

// Returns the sum of two Vector2
Vector2 vec2_add(Vector2 v1, Vector2 v2)
{
    Vector2 result;

    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}
```
- Note we added a comment explaining what our function does. This is good practice and will even allow an IDE to show that info to a user using this function.
    - There are even more elaborate ways to give information about our function to a user but the syntax and level of support will vary from IDE to IDE. See [Doc Comments](./syntax.md#documentation-comments)
- Finally implement our second function.
```c
// You can do it I believe in you.
```
- Ok lets create a `main.c` file and see if everything is working.
- Include `<stdio.h>` for printing
- Also include `"vector.h"` so we can access our functions.
- Create your `main()` function.
    - See [Main Function](./main_function.md)
- Define two variables of the `Vector2` type and assign some values.
    - See [Structs](./types.md#declaring-and-initializing)
- Use the `vec2_add()` function to add the two vectors together and assign the result to a new `Vector2`
```c
Vector2 v3 = vec2_add(v1, v2);
```
- Print out the values of `v3.x` and `v3.y`.
    - TODO printf.md???
- Do the same with `vec2_sub()` and print out the resulting values.

## An Opportunity to Learn About the Compiler







### Preprocessor
gcc -E main.c -o main.i

### Compilation
to assembly
gcc -S main.i -o main.s

You can also compile directly from the C source to assembly:

gcc -S main.c -o main.s

### Assembly

Assemble the .s file into an object file (.o):

gcc -c main.s -o main.o

Or from C directly:

gcc -c main.c -o main.o

### Linking
Link the object file to produce the executable:

gcc main.o -o main