# C Value Types
## Standard Types
### void
- The NULL type, effectively meaning no/unknown type.
- Most used to mark a function that does not return a value.
- A void pointer (void*) is returned by some functions like `malloc()` which is manually cast to the appropriate type by the caller. `int* int_ptr = (int*)malloc(5 * sizeof(int));`
### char
- 8 bit integer
- Signed by default.
- Generally used to store an ASCII character.
- signed
    - min `-128` 
    - max `127`
- unsigned
    - min `0`
    - max `255`
### short
- 16 bit integer.
- Signed by default.
- This is the size used for network ports (0 - 65535)
- signed
    - min `-32,768`
    - max `32,767`
- unsigned
    - min `0`
    - max `65,535`
### int
- 32 bit integer.
- Signed by default.
- By convention the `main()` function should always return the `int` type.
- Unsigned suffix = `u` or `U`
- signed
    - min `-2,147,483,648`
    - max `2,147,483,647`
- unsigned
    - min `0`
    - max `4,294,967,295`
### long
- 32 or 64 bit integer depending on platform and compiler.
- Signed by default.
- Suffix = `l` or `L`
- Unsigned suffix = `ul` or `UL`
- signed (32 bit)
    - min `-2,147,483,648`
    - max `2,147,483,647`
- unsigned (32 bit)
    - min `0`
    - max `4,294,967,295`
- signed (64-bit)
    - min `-9,223,372,036,854,775,808`
    - max `9,223,372,036,854,775,807`
- unsigned (64-bit)
    - min `0`
    - max `18,446,744,073,709,551,615`
### long long
- 64 bit integer.
- Signed by default.
- Suffix = `ll` or `LL`
- Unsigned Suffix = `ull` or `ULL`
- signed
    - min `-9,223,372,036,854,775,808`
    - max `9,223,372,036,854,775,807`
- unsigned
    - min `0`
    - max `18,446,744,073,709,551,615`
### float
- A 32 bit precision floating point number.
- Always signed.
- Suffix = `f`
- `float my_float = 3.14f;`
### double
- A 64 bit precision floating point number.
- Always signed.
- No suffix.
    - long double is possible
    - Suffix = `L` 
- `double my_double = 3.4556234445;`
- `long double my_long_double = 12.3412341231231434423123123L;`
### signed
- Used to specifically declare an integer type as holding a negative or positive value.
- Compilers generally assume this and thus `signed` can be omitted.
- `signed int my_int = 42;`
### unsigned
- Used to declare an integer type as containing only positive values.
- Also used as shorthand on its own for `unsigned int`
- `unsigned short my_ushort = 45;`
- `unsigned long long my_ulonglong = 123456789ULL;`
- `unsigned my_uint = 32;`

***Note: Suffixes on literals (explicit value like 32, 16.5, 0xAC01) act as hints to the compiler as well as to humans as to the intended size of a value. I always use them with floats.***

---
## Extended Integer Types
### <stdint.h>
Provides a standard library of fixed-width integer types. Useful for writing portable code across different platforms since the integer types listed above are not always guaranteed to be the same size in bytes everywhere.

### Fixed-width integer types
Guaranteed to be the size specified.

| Signed | Unsigned | | Equivalent |
|-|-|-|-|
| `int8_t` | `uint8_t` | | `char`/`unsigned char` |
| `int16_t` | `uint16_t` | | `short`/`unsigned short` |
| `int32_t` | `uint32_t` | | `int`/`unsigned`/`unsigned int` |
| `int64_t` | `uint64_t` | | `long` `long long`/ `unsigned long` `unsigned long long` |

### Minimum-width integer types
Guaranteed to be at least the specified size but may be larger.

| Signed | Unsigned | 
|-|-|
| `int_least8_t` | `uint_least8_t` | 
| `int_least16_t` | `uint_least16_t` | 
| `int_least32_t` | `uint_least32_t` | 
| `int64_least_t` | `uint_least64_t` | 

***<stdint.h> contains many more types as well as other features used to work with those types.***

## Structs
A user-defined data type allowing the grouping of multiple variables under a single name.
### Defining a Struct
```c
struct point
{
    int x;
    int y;
}; // Note the ending semi-colon
```
### Declaring and Initializing
```c
struct point p1;
p1.x = 5;
p1.y = 2;
// or
struct point p2 = { 8, 12 };
```
### Structs Within Structs
```c
struct location
{
    char name[50];
    struct point coordinate;
};
```
### Memory Layout
Struct members are stored contiguously in memory possibly with padding depending on the size of each member and their order.
- It is possible to force the compiler to not add padding if required.
    - Padding is added to make the struct more efficient because processors work better on certain sizes of memory.
    - Useful for things like network protocols or file formats where the exact layout matters.
#### GCC / Clang Compilers
```c
struct __attribute__((packed)) my_struct
{
    char a;
    int b;
};
// or 
__attribute__((packed)) struct my_struct
{
    char a;
    int b;
};
```
#### MSVC (Visual Studio)
```c
#pragma pack(push, 1) // 1 means align members on 1-byte boundaries, ie no padding
struct my_struct
{
    char a;
    int b;
};
#pragma pack(pop)
```
## Enums
TODO
## Unions
A union looks somewhat like a struct however all members of a union share the same block of memory.
### Define a Union
```c
union data
{
    int i;        // 4 bytes
    float f;      // 4 bytes
    char str[20]; // 20 bytes
};
```
- The size of this `union` will be 20 bytes. The size is determined by the largest member variable.
### Assigning Values in a Union
```c
union data my_data;
data.i = 5;
data.f = 3.25; // data.i will now have 'garbage' data.
```
### Union Uses
- Type punning (access the same memory as different types)
- Saving memory in embedded systems or resource-constrained environments
- Tagged unions or variant types (usually with an enum to track the type)
## Const
The `const` keyword is used to instruct the compiler that a variable is read-only after assignment.
This means that once a value is assigned it can no longer be changed.
```c
const char* immutable_string = "I can't be changed.";

const short default_port;
default_port = 443;
```
## NULL
`NULL` represents a null pointer constant. Effectively it is a special pointer that does not point to any valid memory location.
- Typically defined as `((void*)0)` 
    - This means a pointer to address 0, which is a reserved memory location.
- Dereferencing a `NULL` pointer causes undefined behavior and usually results in a segmentation fault.
```c
int* ptr = NULL; // ptr that doesn't point to a valid int
if (ptr == NULL)
{
    printf("Pointer is null\n");
}
```
- Many functions will return `NULL` on failure. For example `malloc()`
```c
int* int_ptr = (int*)malloc(sizeof(int));
if (int_ptr == NULL)
{
    printf("malloc returned NULL we don't have enough memory for a single int!\n");
    exit(1);
}
```
## Type Aliasing
We can use the `typedef` keyword to alias existing types. This can improve readability or give special meaning to a type.
```c
typedef unsigned short NetworkPort; // now we can use NetworkPort which will be an unsigned short

NetworkPort rdp = 3389;
// The typedef allowed us to give special meaning to our variable. We now see it represent a port number
```
Windows typedefs many types including pointer types.
```c
typedef char* PCHAR; // the prepended P indicates a pointer

typedef HANDLE* PHANDLE;

// In fact HANDLE is a typedef of void*
// So you can even typedef your typedefs!
```

Typedefing structs is very common simply to allow user to not have to include 'struct` when declaring their variables.
```c
typedef struct
{
    int x;
    int y;
} Point;

Point p1;
```

Function pointers
```c
typedef int (*operation)(int, int); 
// The word operation is now or keyword for a function that 
// matches this signature: returns int, takes 2 parameters int and int

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

// Function that takes a function as a parameter
void print_result(operation op, int x, int y)
{
    print("Result: %d\n", op(x, y));
}

int main()
{
    print_result(add, 3, 4);
    print_result(multiply, 3, 4);
    return 0;
}
// 
```