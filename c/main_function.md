- [Typical Main](#typical-main-function)
- [Main Parameters](#main-parameters)
- [Windows GUI Main](#windows-gui-main-function)
## Typical Main Function
The entry point for your program. Ie where execution begins. The `main()` function is often located in a file named `main.c` but is not a requirement.

- The typical main function has one of two signatures
    - `int main(void) {};`
    - `int main(int argc, char* argv[]) {};`
        - `int main(int argc, char** argv) {};` is functionally equivalent.
- The return type should always be `int`.
- `main()` should always `return 0;` on success and return a non-zero value on failure.
### Main Parameters
- `void`
    - `main()` may have a single parameter of void (which can be omitted) to indicate that main takes no parameters (ie command line arguments `ls -l` the `-l` would be a parameter passed into `main()`) 
- `int argc, char* argv[]`
    - The labels `argc` **argument count** and `argv` **argument vector** are not required and can have whatever names you want but they must be of type `int` and `char* []`/`char\*\*` in that order.
        - **`argc` and `argv` are preferred by convention.**
    - `argc` will always be at least `1`
        - The first argument is always the program name ie `argv[0] == "./program.exe"`
    - `argv` contains an array of strings passed to the program typically by command line.
        - ex `nmap -sV -p 443,445 192.168.0.16`
            ```c
            argc == 5
            argv[0] == "./nmap"
            argv[1] == "-sV"
            argv[2] == "-p"
            argv[3] == "443,445"
            argv[4] == "192.168.0.16"
            ```
## Windows GUI Main Function
Windows uses a custom implementation of a main function for use with GUI programs.
```c
#include <windows.h>
// Entry point for windows GUI application
int WINAPI WinMain(
    HINSTANCE hInstance,     // Handle to the current instance
    HINSTANCE hPrevInstance, // Always NULL
    LPSTR lpCmdLine,         // Command line arguments
    int nCmdShow)            // Window show state (ie, hidden, minimized, show, etc)
{
    // Code ...
    return 0;
}
```