|   | Easy                                    |   | Medium |   | Hard     |
|---|-----------------------------------------|---|--------|---|----------|
|[ ]|[Hello World](#hello-world)              |[ ]|Pointers|[ ]|Threading |
|[ ]|[Simple Compilation](#simple-compilation)|[ ]|        |[ ]|Sockets   |
|[ ]|[Variables Simple](#variables-simple)    |[ ]|        |[ ]|Sockets   |
|[ ]|[If Simple](#if-simple)                  |[ ]|        |[ ]|          |
|[ ]|[Loops Simple](#loops-simple)            |[ ]|        |[ ]|          |
|[ ]|[Stack Array](#stack-array)              |[ ]|        |[ ]|          |
|[ ]|[Heap Array](#heap-array)                |[ ]|        |[ ]|          |
|[ ]|[Search an Array](#search-an-array)      |[ ]|        |[ ]|          |
---
---
### Hello World
[main_function.md](./main_function.md), [files.md](./files.md)

Create a `.c` file and populate it with a 'hello world' program.
- Include `<stdio.h>` to access the `printf()` function.
    ```c
    #include <stdio.h>
    ```
- Use a parameter-less main function as your entry point
    ```c
    int main(void)
    {
        // ...
    }
    ```
- Print out your hello world message.
    - Be sure to include the `\n` (new line escape sequence) as `printf()` does not include this by default.
    ```c
    printf("Hello, world!\n");
    ```
- Remember to `return 0;` on success;
    ```c
    int main(void)
    {
        // ...
        return 0;
    }
    ```
---
### Simple Compilation
[compiling.md](./compiling.md)

Compile your 'Hello World' program using `gcc`. Either use a linux OS or utilize WSL2 in Windows.   
    `gcc -o main main.c`
- Replace `main` with the name you want to output your program as.
- Replace `main.c` with whatever you called your hello world `.c` file.
- Execute with `./main`


---
### Variables Simple
[types.md](./types.md)

Create at least 3 variables of different types and print their values out.
- Include <stdio.h> and use the `printf()` function (see [Hello World](#hello-world)) to print the values.
    - You will need to research what **format specifier** is required for each of your 3 types.
    ```c
        int int_value = 1234;
        printf("integer specifier is \%d: %d\n", int_value);
    ```
- Bonus 1: Print the memory addresses of these variables.
- Bonus 2: Print the memoru addresses in hexidecimal notation.
---
### If Simple
[flow_control.md](./flow_control.md)

Use conditional statements (`if`, `else if`, `else`) to execute different blocks of code based on the current time.
- Execute print statements under the following conditions:
    - If seconds is odd print -> the seconds are odd: `current seconds`
    - If seconds is even print -> the seconds are even: `current seconds`
    - If minutes is a multiple of 3 ignore the odd / even conditions and print -> minutes is a multiple of 3: `current minutes`
    - If seconds is 2 print -> the seconds are 2: `current seconds`
        - **Do not print the seconds is even message if seconds is 0**
- Use the code snippet to help you with getting the time.
```c
#include <time.h>

int main(void)
{
    time_t now = time(NULL); // get time now

    struct tm* local = localtime(&now); // get as local time

    // access specific parts of time
    // inspect struct tm to find its members
    // You do not have to assign to int hour/ int min, this is just an example
    int hour = local->tm_hour; 
    int min = local->tm_min;

    // NOTE: be careful with the month and year member of struct tm

    // Your code here...

    return 0;
}
```

---
### Loops Simple

---
### Stack Array

---
### Heap Array

---
### Search an Array
Create a function that uses a `for` loop to iterate an array and find a specific value. Return the index of that value.
- Disregard multiple matching values and simply return the first index with a matching value.
- You may use a 'global' array to keep things simple but if you want to practice pointers have the function take a pointer to the array to search.
- The array can hold any data type you want but I suggest a integer type for simplicity.
- Determine what the function should do when no match is found. Consider usage of this function and what is 'safe-code' practices.
---