*We will be using Linux so if you are on windows make sure you are running in WSL.
In the bottom left corner of VSCode you can switch to WSL by clicking the `><` button and selecting `Connect to WSL`*

## Function Overview
Functions are reusable blocks of code that perform a specific task. 
- They are used to break complex problems into smaller parts. 
- Functions organize logic into self-contained chunks making code more readable (particularly if the function has a descriptive name). 
- Functions are write once and use many times reducing code duplication. They can even be used across many projects.
- They can make code easier to debug, test and to update specific functionality.

## Math Function
Lets create a math function to 'clamp' a value.
- Copy your `main.c` from `c/src/hello_world` into a new folder `c/stc/hello_clamp`
- Once its copied we will add our function to our copied `main.c`
    - If you haven't already you can change directory in your terminal to your `hello_clamp` folder.
- Start by creating our function prototype.
```c
#include <stdio.h>

float clamp(float min, float max, float value); // function prototype

int main(void)
{
...
```
### Function Prototype
`float clamp(float min, float max, float value);`
`<return type> <function name>(<param type> <param name>, ...);`
What we have done here is told the compiler that we will implement a function that will return a `float` value. It will be named `clamp` and it will take 3 parameters of the following types `float`, `float`, `float`.

We also gave each parameter a name: `min`, `max`, and `value`. These names are not required in a function prototype (see [scope.md](./scope.md)) but including them here helps with readability/understanding. When we implement the function itself we do not have to name our parameters the same as they are named in the prototype. *(There really is no reason to not have the names match but it is something you can do.)*

### Implementation
We will now implement our function. Lets place it after our `main` function.
- In order to clamp a value between 2 values we must define the lower/minimum and upper/maximum values. We will also need to pass in the value we want to clamp.
- This is our function definition:
```c
...
int main(void)
{
    ...
}

float clamp(float min, float max, float value)
{
    // Code ...
}
```
- Notice it matches the prototype exactly but now has curly braces for our code block `{ }`
    - The `{ }` have defined a new scope now as well.
    - Currently we have 3 scopes.
        - The 'global' scope. Our function prototype is there for example.
        - main() has its local scope
        - clamp() has its local scope
- Next lets add the actual logic to our function.
    - Its fairly simple. If our value we are clamping is too small then we return the minimum value.
    - If our value is too big we return our maximum value.
    - Otherwise we return the current value.
```c
float clamp(float min, float max, float value)
{
    if (value < min)
        return min; // Recall we do not require a code block { } if we only have 1 statement.
    
    if (value > max)
        return max;
    
    return value; // Our value is not too small or too big so we return it.
}
```

## Calling Our Function
Now that our function is implemented we will call it from our `main()` function.
- See [types.md](./types.md) for more information on floats.
```c
int main(void)
{
    // Declare a float value to clamp
    float my_float = 3.75f;

    printf("Hello world!\n");

    // Call out clamp function and store its return value in a new variable
    float clamped_value = clamp(1.0f, 2.0f, my_float);
    
    // Print out our results
    printf("%.2f clamped is %.2f\n", my_float, clamped_value);
    // %.2f means to print a float with 2 decimal places
    return 0;
}
```
- Compile this code with the same gcc command as our hello_world example and run it. Did you get the expected output?
- Lets comment out our prototype and see what happens when we compile.
```c
#include <stdio.h>

// float clamp(float min, float max, float value);

int main(void)
{
...
```
- You should get a warning about implicit declaration and an error.
```
main.c: In function 'main':
main.c:13:27: warning: implicit declaration of function 'clamp' [-Wimplicit-function-declaration]
   13 |     float clamped_value = clamp(1.0f, 2.0f, my_float);
      |                           ^~~~~
main.c: At top level:
main.c:21:7: error: conflicting types for 'clamp'; have 'float(float,  float,  float)'
   21 | float clamp(float min, float max, float value)
      |       ^~~~~
```
- This output indicates that we are trying to use our function before we have declared/defined it.
    - You are allowed to use implicit declarations but they default to a return type of int
    - It is best practice to NOT use implicit declarations
- Lets fix our error by moving our `clamp()` function above our `main()` function.
```c
#include <stdio.h>

// float clamp(float min, float max, float value);

float clamp(float min, float max, float value)
{
    ...
}

int main(void)
{
    ...
}
```
- Now compile your program and you will see it works fine.
- As you can see we don't need the function prototype as long as our function is defined before it is called.

## Reusability Beyond This Program
You may find that some of your functions are useful beyond the scope of your current project.
When that is the case its best to move our functions into their own files so they can be added to any project.
This is also useful to simply organize our code and avoid having single files with thousands of lines.
- Create two new files `hello_math.c` and `hello_math.h`.
- Open `hello_math.h`
