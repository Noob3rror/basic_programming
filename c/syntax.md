# Syntax

The syntax of a language is the set of rules that define how to language works and what is valid code.

---

## Case-Sensitive
C is case sensitive. Variable names, reserved keywords, etc must be in the correct upper or lower case.
```c
// These are two separate variables due to capitalization
my_variable = 1; 
my_Variable = 2; 
```

---

## Reserved Keywords
A specific set of words are reserved by the C language and cannot be used for things like variable names.
| | | | | | |
|-|-|-|-|-|-|
|Control Flow|**if**|**else**|**switch**|**case**|**default**|
|            |**while**|**do**|**for**|**break**|**continue**|
||**return**|**goto**|
||
|Data Types|**char**|**int**|**float**|**double**|**short**|
||**long**|**void**|**signed**|**unsigned**|
||**_Bool** (C99)|**_Complex** (C99)|**_Imaginary** (C99)|
||
|Type Qualifiers|**const**|**volatile**|
||**restrict** (C99)|**_Atomic** (C11)|
||
|Storage Class|**auto**|**register**|**static**|**extern**|**typedef**|
||
|Structuring|**struct**|**union**|**enum**|**sizeof**|
||
|Other|**inline** (C99)|**_Alignas** (C11)| **_Alignof** (C11)| **_Generic** (C11)| **_Noreturn** (C11)|
||**_Static_assert** (C11)|**_Thread_local** (C11)|

---

## Whitespace
Whitespace (*spaces, tabs, new lines*) is ignored in C. More specifically whitespace beyond the required spacing to allow the compiler to distinguish one token from another. `return0;` cannot be interpreted correctly as `return 0;`, the compiler would most likely see `return0` as a variable that was not declared.

The following code samples are both valid syntax.
```c
int main(int argc, char* argv[]) {
    int my_variable = 5;
    return 0;
}
```
```c
        int     main   (    int  argc   ,
  char    *    argv[]    )
{ int     my_variable=5       ;return 
0
;      }
```

---

## Statements
A statement ends with a semicolon `;`. 
```c
x = y + 2;
```
---
## Braces and Blocks
Braces are used to group statements into blocks (see [scope.md](./scope.md) to see how they also define scopes). Used for functions, conditional blocks `if`, `for`, etc.
```c
if (x > 0)
{
    printf("Positive\n");
}
```
---
## Identifiers
Identifiers are the names for functions, variables, etc.
- Identifiers must start with a letter (A-Z, a-z) or underscore `_`, and followed by letters, digits, or underscores.
```c
_tempValue_1
```
---
## Comments
Comments are notes, messages, etc that are ignored by the compiler and used to explain/document the code or to prevent code from compiling without having to delete it.
- Single-line comment `//`
```c
// This is a single line comment
int main(void) // They can also be placed at the end of a line of code
{
    return 0;
}
```
- Multi-line comment `/* */
```c
/*
This is 
a multiline 
comment
*/

/* As is this */

int main(int argc/* Valid comment by generally avoid this*/, char* argv[]) { return 0; }
```
### Documentation Comments
TODO

---
## Punctuation
TODO

---
## Strings and Characters
TODO