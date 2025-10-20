# Variables
A variable is a named location in your programs memory used to store data.

## Parts of a Variable
#### Name
The name of a variable is a label used to refer to a piece of memory
#### Type
Indicates what kind of data is stored in the variable (`int`, `char`, `float`, etc)
#### Value
The actual data stored in the variable
#### Scope
Where the variable is accessible within the code (see: [scope.md](./scope.md))
#### Lifetime
How long the variable exists (automatic, static, dynamic)

```c
int count = 10;
// count -> name
// int -> type
// 10 -> value
```

## Naming Rules
May only contain letters (A-Z, a-z), numbers (0-9), and the underscore (_)

Cannot begin with a number

Cannot be a reserved keyword (`return`, `float`, `if`, etc)

Cannot be a name already in use in the same scope

```c
int value = 1;
if (value > 1)
{
    int new_value = 2;
}

if (value < 1)
{
    int new_value = 3;
}
// Naming both these variables `new_value` is fine because they are in separate scopes

if (value == 1)
{
    int value = 2; // error name collision
}
// This causes a name collision because `value` outside of the if block is visible inside of this block.
```

You should avoid naming variables the same names as functions as it gets a little weird.

```c
int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int main = 1; // this is fine
    int add = 3; // still fine
    int value = add(main, add); // causes an error on the function name

    // However the following is valid because `add` variable is declared after the function call
    int main = 2;
    int v = add(main, 3);
    int add = 4;
}
```

## Naming Styles
|Style|Example|Notes|
|-|-|-|
|snake_case| int user_count = 0;|All lower-case with '_' representing a space. Standard for Python.|
|camelCase|int userCount = 0;|First word of the name is lower-case and all following words are capitalized. Fairly common alternative to snake casing.|
|PascalCase|int GetUserCount();|Each word is capitalized. Very common in OOP languages for class and method names particularly in Windows.|
|Hungarian Notation|float fSpeed = 1.0f;|Each word is capitalized and the name is prepended with a type indicator. `f` for float, `n` for integer, etc.| 
|ALL_CAPS|const int MAX_BUFFER_SIZE = 256;| Often to indicate constants or macros.|
|_underscore|int _internalCount = 0;| Sometimes used to indicate private or internal use. Can be prepended to any style.|

What name style is used will depend on the type of variable/macro, its usage, and whatever style guide you are following dictates.

*A note on Hungarian notation. Due to modern IDEs its much rarer to see this notation as its primary benefit of indicating the type of a variable is less relevant today. You will still find it or modified versions of it in legacy or backwards compatible code bases.*