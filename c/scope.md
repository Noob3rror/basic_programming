- [Scope](#scope)
    - [Local Scope](#block-or-local-scope)
    - [Global Scope](#file-or-global-scope)
    - [Prototype Scope](#function-prototype-scope)
# Scope
Scope is the region of the program that a variable, function or identifier is visible and accessible.
## Block or Local Scope
- This is the scope of variables declared inside of `{}` (*inside functions, loops, if statements*)
    ```c
    void my_function()
    {
        int x = 5; // visible anywhere within this function

        if (x == 5)
        {
            int y = 10; // visible only within this if block
            x = x - 1; // Valid: x is visible here because it was declare outside of the if statement
        }

        x = x + y; // Error: y is not visible here
    }
    ```
## File or Global Scope
- Variables declared outside of any function
- Accessible from anywhere after the point of declaration within the file.
    - See `extern` for access outside of a file.
    - See `static` for internal linkage.
    ```c
    int global_int = 42;

    void my_func()
    {
        printf("%d\b", global_int); // Accessible
        
        global_short += 1; // Error: variable has not been declared or defined
    }

    short global_short = 1; // Move above my_func() to resolve error
    ```
## Function Prototype Scope
- Applies to variable names used in function prototypes.
- Effectively when declaring a prototype the parameter names do not matter and can even be omitted.
- See more in functions document.