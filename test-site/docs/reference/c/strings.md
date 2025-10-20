# Strings
In C, a string is an array of characters terminated by a null character (`'\0'`). 
C does not have a built-in string type like some higher-level languages; instead, strings are handled as arrays of type `char`.

## Creating a String
- String literals are created by surrounding text with double quotes `" "`.
- Strings are type as character pointers `char*` or character arrays `char []`.
    - Character arrays reduce to character pointers so they are effectively the same.
    - An important difference, however, is the a `char []` will copy the string. **See below.**
- Characters are defined using single quotes `' '`.
- The following examples are functionally equivalent when creating a string.
    ```c
    char str[] = "Hello"; // the null terminator is implicit

    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // the null terminator must be included manually

    char* str = "Hello"; // the null terminator is implicit
    ```
### Implicit String Literal Concatenation
String literals next to each other will be concatenated automatically by the compiler.
```c
char* str = "Hello" "world";
// str contains "Helloworld\0"
```
### Multiline Strings
A string can be split of multiple lines if necessary using `\`. Caution it can become easy to introduce bugs and make your code less readable.
- **`\` MUST be the last character in the line or it will cause an error.**
    - You cannot even put a single line comment following the `\`.
    ```c
    char str[] = "This is a long string \
    that I have broken up on two lines.";
    ```
### Immutable String
String literals are immutable. (They cannot be changed at runtime.) This is because they are stored in the output binary in a read-only section of memory (often `.rodata` segment).
```c
char* str = "Hello";
str[0] = 'h'; // Error: segmentation fault
// This is undefined behavior because the memory address where the 'H' in "Hello" is stored is marked as read-only.
```
### Mutable String
If you need your string to be mutable you must copy it out of its read-only location.
```c
char str[] = "Hello"; // This will copy the string from the .rodata segment and into stack memory which is modifiable
str[0] = 'h'; // valid
```

## Working with Strings
### Escape Sequences
- Certain characters must be 'escaped' in order to be properly recognized by the compiler as characters or special functions.
    |Escape Sequence|	Meaning|
    |-|-|
    |`\n`|	Newline|
    |`\t`|	Horizontal tab|
    |`\r`|	Carriage return|
    |`\\`|	Backslash (\)|
    |`\"`|	Double quote (")|
    |`\'`|	Single quote (')|
    |`\?`|	Literal question mark (?)|
    |`\a`|	Alert (bell)|
    |`\b`|	Backspace|
    |`\f`|	Form feed|
    |`\v`|	Vertical tab|
    |`\0`|	Null character (end of string)|
    |`\ooo`|	Octal value (e.g., \141 for 'a')|
    |`\xhh`|	Hexadecimal value (e.g., \x61 for 'a')|
### String Functions
`<string.h>` contains several functions for working with string data.
- These functions **do not do bounds checking** and the programmer must ensure memory safety.
    - Do research either online or with the `man` pages to understand how these functions work as you need them.

    |Function|Description|
    |-|-|
    |`strlen(str)`          |Length of the string (excluding null terminator `'\0'`)|
    |`strcpy(dest, src)`    |Copies `src` into `dest`|
    |`strncpy(dest, src, n)`|Copies up to `n` chars from `src` to `dest`|
    |`strcat(dest, src)`    |Appends `src` to the end of `dest`|
    |`strcmp(a, b)`         |Compares strings `a` and `b` (*returns 0 if equal*)|
    |`strncmp(a, b, n)`     |Compares up to `n` characters of `a` and `b`|
    |`strchr(s, c)`         |Returns pointer to first occurrence of `c` in `s`|
    |`strstr(hay, needle)`  |Finds first occurrence of `needle` in `haystack`|
    |`memset(ptr, val, n)`  |Fills first `n` bytes of `ptr` with `val`|
    |`memcpy(dest, src, n)` |Copies `n` bytes from `src` to `dest`|

- You cannot use standard comparison operations on strings as they will not return what you expect.
    ```c
    char* str1 = "hello";
    char str2[] = "hello";

    if (str1 == str2) // The comparison made is actually comparing the pointers
    {
        // str1 points to the address in read-only memory
        // str2 points to an address on the stack that "hello" was copied into
        printf("The strings are the same.\n");
    }

    // The following will properly evaluate to true but not because "hello" is being compared to "hello"
    char* str1 = "hello";
    char* str2 = "hello";

    if (str1 == str2) // Once again we are comparing pointers not strings
    {
        // str1 points to the address in read-only memory
        // str2 also points to the same address
        printf("The strings are the same.\n"); // This will print
    }

    // The reason this works now is because the compiler only put one "hello" into .rodata
    // So if you use the string literal "hello" any where in your code it will always refer
    // to a single instance stored in read-only memory in the binary.
    ```