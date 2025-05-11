# Flow Control
## if
- Defines a block of code to execute if some condition evaluates as true.
    ```c
    int a = 2;
    if (a > 1) // Evaluate condition; is 'a' greater than 1
    {
        // Do something here.
    }
    ```
- If only 1 line of code is to be executed the `{}` may be omitted.
    - This is true for all code block statements (`if`, `for`, `while`, `else`, etc)
    ```c
    if (true) // This will always evaluate as true
        printf("This will always print.\n");
    // or
    if (true) printf("Print me!\n"); // It can all be placed on a single line
    ```
    ***Note: Be careful if omitting the {} as this is an easy way to introduce bugs.***
## else
- Used with the `if` statement to give an alternate block of code to execute when the condition evaluates as false.
- `else` must always be the last block with `if`, `else if`.
    ```c
    if (false) // Will always evaluate as false
    {
        // Code here will never execute
    }
    else
    {
        // Code here will always execute
    }
    ```
## else if
- Used with the `if` statement to add an additional evaluation and code block to execute.
- The `if` and `else if` blocks are evaluated top to bottom and the first one to evaluate to `true` is executed. If none are `true` none of the code blocks will execute unless an `else` block is present then it will execute its block of code. 
    ```c
    if (false)
    {
        // Will not execute
    }
    else if (true)
    {
        // Will execute
    }
    // If needed aditional else if blocks can be added as well as an else block at the end
    ```
## switch
- Similar to an `if` statement but instead of evaluating for true it executes the code block with the matching `case` statement.
- `case` values (0, 1, 2, 3 in this example) **must be resolvable at compile time**. This means they must be constant integer expressions.
    - Integer literals: `-1`, `0`, `1`, `200`, `3333`, ... > `case 7:`
    - Character literals: `'A'`, `'b'`, `'5'`, `'&'` ... > `case 'b':`
    - `#define` constants: `$define FOO 15` > `case FOO:`
    - `enum` values: `enum Color { RED = 1 };` > `case RED:`
    ```c
    int my_int = 3;
    switch (my_int)
    {
        case 0:
            // no break statement causes the switch block to 'fall thru'
        case 1:
        case 2:
            printf("my_int is either 0, 1, or 2\n");
            // If my_int is 0 then case 0, case 1 and case 2 will execute
            // if my_int is 1 then case 1 and case 2 will execute
            // if my_int is 2 then only case 2 will execute
            break;
        case 3:
            printf("my_int is 3\n");
            break;
        default:
            // default executes when none of the cases match the condition 'my_int' in this case
            // or if a case above it falls thru (case 3: here)
            printf("my_int is some number not covered by the current cases\n");
            break; // this break is not required but is good practice
    }
    ```
## case
- See `switch`
## default
- See `switch`
## while
- Loops over a block of code until the condition no longer evaluates as true.
- The condition is checked at the start of each iteration
    ```c
    int a = 0;
    while (a < 5) // Loops until a is greater than or equal to 5
    {
        printf("%d\n", a); // prints: 0, 1, 2, 3, 4
        a += 1; // increment a by 1
    }
    ```
## do while
- Similar to the `while` loop but is guaranteed to execute at least once.
    ```c
    do
    {
        printf("just once.\n");
    } while (0); // 0 is equivalent to false; thus the do block will execute only once
    ```
## for
- Conditional looping; containing an initialization, condition and increment sections.
    ```c
    int my_array[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; i++)
    {
        // initializes i to 0
        // evaluates the condition on each loop: i < 5
        // increments on each loop: i++

        // Useful for indexing into an array
        printf("Index %d = %d\n", i, y_array[i]); // prints: Index 0 = 2, Index 1 = 4 ...
    }

    // Easy to index out of bounds which can lead to vulnerabilities and bugs
    // Safer version
    for (int i = 0; i < sizeof(my_array); i++)
    {
        // sizeof(my_array) will return the number of elements in the array

        //additional safety check
        if (i > sizeof(my_array) || i < 0) // check that i is between 0 and number of elements in the array
        {
            break; // exit the loop early
        }

        // These safety precautions are applicable whenever dealing with array indexing or pointers
    }
    ```
## break
- Breaks out of loops and cases.
- See above
## continue
- Causes a loop to stop the current execution of a code block (`while`, `do while`, `for`) and continue at the next iteration.
    ```c
    int x = 0;
    for (;;) // An empty for loop like this is the same as a `while (true)` ie an infinite loop
    {
        x += 1;
        if (x == 2) { continue; } // if x is 2 skip the rest of the code and return to the top of the for loop

        printf("x is %d\n", x); // will print: x is 1, x is 3, x is 4, x is 5 then break out

        if (x == 5) { break; } // condition to break out of the infinite loop
    }
    ```
## return
- Used to immediately return from a function.
- Must return a value matching the return type of the function or return nothing if void function
    ```c
    int my_func(int value)
    {
        return value + 5;
    }

    void my_other_func()
    {
        printf("This function returns nothing\n");
        return;
    }

    void my_other_other_func(int value)
    {
        printf("I print this!\n");
        if (value == 2)
        {
            printf("I print this only if value is 2 then return early\n");
            return; // The third printf() will not execute in this case due to the return
        }

        printf("I only print if value is not 2\n");
        // return can be omitted as this is a void function and code execution will make it to the closing `}`
    }
    ```
## goto
- Allows you to jump directly to a specified 'label'
- Try to avoid `goto` as they are considered "bad practice"
- However they can be used to very effectively in some situations and at the assembly level their use is essentially required.
    ```c
    int my_func(int value)
    {
        if (value < 1)
        {
            // Note: this is an overly simplistic example and in this case you would normally just return 0 here
            goto failure;
        }

        printf("value %d\n", value);
        return value;
    failure: // label
        return 0;
    }

    ```



  auto              
const       default     
enum        extern
               goto   
register 
            sizeof      static
struct      typedef     union
        volatile