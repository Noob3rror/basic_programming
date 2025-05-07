

# Intro
## High-Level vs Low-Level
High-level languages include Python, C#, Go, Javascript, Rust and C. Tho C is much closer to a low-level language.

> **High-level** languages are human readable as their syntax close resembles human language. They abstract away hardware details making them easier to read, write, and maintain.

> **Low-level** languages are closer to machine code. Proide direct control over hardware and memory and are less abstract. For example in high-level languages you rarely if ever directly interact with CPU registers but you do in a low-level language like x86 assembly.

## Compiled vs Interpreted
C is a compiled language, whereas a language like Python is interpreted.
> **Compiled** languages must but *compiled* or *built*. The source files are ran thru a compiler (gcc, msvc, cl.exe, etc) and built into binary files containing machine code that can be directly executed by a CPU. Due to this compiled languages are almost always faster. However, because they are compiled they must be compiled targeted at each platform you intend to run them on.

> **Interpreted** languages are not compiled to binary and instead are *'compiled'* at run time. They require an interpreter to be installed in order to execute their code. Because of this interpreted languages tend to be slower. However, because they can run on any platform that its interpreter is they tend to be very portable.

## C vs Assembly
Here we will see an example of a simple c program and it's compiled assembly representation. *C source code is generally very close to the final assembled version.*

```c
#include <unistd.h>

int main() 
{
    const char *msg = "Hello, world!\n";
    write(1, msg, 14);  // fildes=1 is stdout, 14 is the length of the string
    return 0;
}
```

```asm
main:
    mov     rax, 1          ; syscall number 1 = sys_write
    mov     rdi, 1          ; file descriptor (stdout)
    lea     rsi, [rip+msg]  ; address of the message string
    mov     rdx, 14         ; number of bytes to write
    syscall                 ; invoke the kernel
    xor     eax, eax        ; return 0
    ret
msg:
    .string "Hello, world!\n"
```

### Comparison

```c
int main()
```
```asm
main:
```
- These mark the entry point; where the program begins (This is not entirely true depending on the OS programs start in _start() or similar for example but it only performs basic setup before calling your main() function)

```c
const char *msg = "Hello, world!\n";
```
```asm
msg:
    .string "Hello, world!\n"
```
- Here C creates an immutable or read-only memory allocation to store "Hello, world!\n" directly in the binary memory.
```c
write(1, msg, 14);
```
```asm
    mov     rax, 1          
    mov     rdi, 1          
    lea     rsi, [rip+msg] 
    mov     rdx, 14         
    syscall                
```
- The first instruction `mov rax, 1` places the value `1` into the `rax` register. `1` represents the kernel function sys_write which is what `write()` invokes.
- Next `mov rdi, 1` places `1` into `rdi` register which represents the first parameter of `write()`
- `lea rsi, [rip+msg]` places the memory address of our buffer (which points to the H in our "Hello, world\n" string) into `rsi`; the second parameter of `write()`.
- Then the third parameter of `write()` `14` is placed into the `rdx` register.
- Finally `syscall` calls the kernel function loaded into `rax`; `sys_write`

```c
return 0;
```
```asm
    xor     eax, eax     
    ret
```
- Here we `xor` the `eax` register with itself which will place `0` into `eax`. This is more efficient than `mov eax, 0`. (Ie it takes fewer clock cycles.) `eax` is used as the return value.
- Finally `ret` will perform the same function as a `return` and move the stack pointer backer to the caller's address.

## C Files
C source code is divided into two types of files. `.c` and `.h` files.
See [files.md](./files.md) for a more in depth explaination.



`ssize_t write(int fildes, const void *buf, size_t nbyte);`
- `ssize_t` Returns a signed integer
- `int fildes` File descriptor to write to
- `const void *buff` Address of a buffer to write
- `size_t nbyte` Number of bytes to write
