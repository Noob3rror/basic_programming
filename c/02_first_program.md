*We will be using Linux so if you are on windows make sure you are running in WSL.
In the bottom left corner of VSCode you can switch to WSL by clicking the `><` button and selecting `Connect to WSL`*

## Hello World
[main_function.md](./main_function.md), [files.md](./files.md)
- Create a folder in `src` directory called `hello_world` if not already present.
- In your terminal (`Terminal` -> `New Terminal`) change directory to `c/src/hello_world`

- Create a `main.c` file and populate it with a 'hello world' program.
- Include `<stdio.h>` to access the `printf()` function.
    ```c
    #include <stdio.h>
    ```
- Use a parameter-less main function as your entry point
    ```c
    int main(void)
    {
        // Code here...
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

## Compile
[compiling.md](./compiling.md)
- With your source file created lets compile it.
- In your terminal:
    - `gcc main.c`
    - `ls`
    ```
    user@DESKTOP:basic_programming/c/src/hello_world$ ls
    a.out  main.c
    ```
- Notice the new file `a.out`.
    - This is the default naming convention we can provide an output file name with the `-o` option.
    - `gcc main.c -o hello_world`
- Execute `a.out` or whatever name you used for the output file.
    - `./a.out`
    ```
    user@DESKTOP:basic_programming/c/src/hello_world$ ./a.out
    Hello world!
    ```

## Errors
- Next lets create an error and see what the compiler does.
- In your `main.c` file replace `\n` with an actual new line.
```c
    printf("Hello world!
        ");
```
- If you are using an IDE you'll notice that the editor has underlined the errors in your code.
- Disregard those and recompile the program.
    - `gcc main.c`
    - The output from `gcc` show 4 errors and 2 warnings. Errors tend to cascade and cause additional errors.
        - It is generally best to resolve your warnings/errors from top to bottom because of this.
    ```
    main.c: In function ‘main’:
    main.c:5:12: warning: missing terminating " character
        5 |     printf("Hello world!
        |            ^
    main.c:5:12: error: missing terminating " character
        5 |     printf("Hello world!
        |            ^~~~~~~~~~~~~
    main.c:6:9: warning: missing terminating " character
        6 |         ");
        |         ^
    main.c:6:9: error: missing terminating " character
        6 |         ");
        |         ^~~
    main.c:8:5: error: expected expression before ‘return’
        8 |     return 0;
        |     ^~~~~~
    main.c:8:14: error: expected ‘;’ before ‘}’ token
        8 |     return 0;
        |              ^
        |              ;
        9 | }
        | ~    
    ```
- We can see that the output will indicate the file (`main.c`) as well as the line number and column where the errors occurred.
- The first warning tells us that the `"` character is missing its terminating `"`
    - We can not split a string literal over multiple lines in this way.
    - See [strings.md](./strings.md) to see how we can split a string literal correctly.
- Restore your main.c to how it was.