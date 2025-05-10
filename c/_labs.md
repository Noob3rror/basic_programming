|   | Easy                                    |   | Medium                            |   | Hard     |
|---|-----------------------------------------|---|-----------------------------------|---|----------|
|[ ]|[Hello World](#hello-world)              |[ ]|                                   |[ ]| |
|[ ]|[Simple Compilation](#simple-compilation)|[ ]|[Search an Array](#search-an-array)|[ ]|   |
|[ ]|[Variables Simple](#variables-simple)    |[ ]|                                   |[ ]|   |
|[ ]|[If Simple](#if-simple)                  |[ ]|Sockets                            |[ ]|[Login](#login)|
|[ ]|[Loops Simple](#loops-simple)            |[ ]|Threading                          |[ ]|[Login 2](#login-2)|
|[ ]|[Stack Array](#stack-array)              |[ ]|                                   |[ ]|[Login 3](#login-3)|
|[ ]|[Heap Array](#heap-array)                |[ ]|                                   |[ ]|[Login 4](#login-4)|
|[ ]|Pointers                                 |[ ]|                                   |[ ]|          |
---
## Easy
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
### Compilation
[compiling.md](./compiling.md)

Compile your 'Hello World' program using `gcc`. Either use a linux OS or utilize WSL2 in Windows.   
    `gcc main.c -o main`
- Replace `main` with the name you want to output your program as.
- Replace `main.c` with whatever you called your hello world `.c` file.
- Execute with `./main`


---
### Variables
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
### If
[flow_control.md](./flow_control.md)

Use conditional statements (`if`, `else if`, `else`) to execute different blocks of code based on the current time.
- Execute print statements under the following conditions:
    - If seconds is odd print -> the seconds are odd: `current seconds`
    - If seconds is even print -> the seconds are even: `current seconds`
    - If minutes is a multiple of 3 print -> minutes is a multiple of 3: `current minutes`
        - **Do not print the odd / even condition if this condition is true.**
    - If seconds is 2 print -> the seconds are 2: `current seconds`
        - **Do not print the seconds is even message if this condition is true.**
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
### Loops
Using the provided array and various loops (`for`, `while`, `do while`) perform the following tasks:
- Print the contents of the strings array 1 element per line
- Print them in reverse order
- Print at least 1 element then stop iterating if the current element starts with `e`. `strings[0][0]` will give you the first letter of the first string.
- Be sure to use each of the 3 loops `for`, `while`, `do while`.
```c
const char* strings[] = {"elephant", "cat", "giraffe", "gorilla", "cow"};
```
---
### Stack Array
Create an array on the stack cotaining 15 elements. Safely loop over the array and assign a unique value to each element.
- The type of the array is up to you.
- Use a `#define` macro to set the size of the array. 
---
### Heap Array
Create an array of `uint32_t` on the heap. Print the values of each element of the array.
- Use `malloc` from `<stdlib.h>` to allocate your array
- Print each element on new lines.
- Run your code several times. 
---
## Medium
---
### Search an Array
Create a function that uses a `for` loop to iterate an array and find a specific value. Return the index of that value.
- Disregard multiple matching values and simply return the first index with a matching value.
- You may use a 'global' array to keep things simple but if you want to practice pointers have the function take a pointer to the array to search.
- The array can hold any data type you want but I suggest an integer type for simplicity.
- Determine what the function should do when no match is found. Consider usage of this function and what is 'safe-code' practices.
---



## Hard

---
### Login
Create a program that a user logs into. 
- Prompt the user to add a user name and password or to log in.
- Store the user name and associated password in a file on disk (in the same directory as the program is fine).
    - If a name is already present inform the user that user name is unavailable.
    - Give the user a method to 'cancel' adding a new user and return to the starting prompt.
- Validate login attempts with the stored user name/password file.
    - Print a message for login success or failure.
---
### Login 2
Add a default user ie 'admin'.
- Print a special message indicating 'admin privileges' on successful log in.
- The 'admin' user should be able to log in without needing the user name/password stored in the file.
- Be sure to reserve the 'admin' user name so a user cannot add it to the password file.
- Bonus 1: Prevent users from being able to use `strings` to find the 'admin' log in information (name and password).
- Bonus 2: Prevent users from being able to memory dump your program and find the log in name and password (ie in plain text)
---
### Login 3
Assuming you haven't gone above and beyond already, protect the passwords. Ie do not store plain text passwords.

---

### Login 4
Protect your log in program from brute force/dictionary attacks.
- Whatever method you implement be sure to inform valid users of any pertinent information necessary.
    - For example if you will lock a user from logging in after 5 failed attempts inform the user how many attempts remain.
- Use may use multiple methods to protect your program.
- Carefully consider your implementation; you may need to update your password file format.
    - You can assume that your password file is `read-only` or even stored on a server somewhere in the ether.
- Bonus: Using a lock-out approach allow the failed attempt count to reset after a specified period of time.
---