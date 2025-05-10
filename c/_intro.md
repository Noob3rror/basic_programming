

# Intro
C is a general-purpose, procedural programming language developed in the early 1970s by Dennis Ritchie at Bell Labs. It was originally designed to write the Unix operating system and has since become one of the most widely used and influential programming languages in the world.

***Key Characteristics:***
- **Low-level access**: Allows manipulation of memory via pointers.
- **Efficient and fast**: Close to machine-level operations, making it ideal for systems programming.
- **Portable**: Code can be compiled and run on many different types of machines with minimal changes.
- **Compiled**: C programs are turned into machine code using a compiler like GCC or Clang.

***Typical Uses:***
- Operating systems (Unix, Linux, Windows kernels)
- Embedded systems (firmware in micro-controllers)
- Compilers and interpreters
- Game engines
- Networking software

---

## High-Level vs Low-Level
High-level languages include Python, C#, Go, Javascript, Rust and C. Tho C is much closer to a low-level language.

> **High-level** languages are human readable as their syntax closely resembles human language. They abstract away hardware details making them easier to read, write, and maintain.

> **Low-level** languages are closer to machine code. Provide direct control over hardware and memory and are less abstract. For example in high-level languages you rarely if ever directly interact with CPU registers but you do in a low-level language like x86 assembly.

---

## Compiled vs Interpreted
C is a compiled language, whereas a language like Python is interpreted.
> **Compiled** languages must but *compiled* or *built*. The source files are ran thru a compiler (gcc, msvc, cl.exe, etc) and built into binary files containing machine code that can be directly executed by a CPU. Due to this compiled languages are almost always faster. However, because they are compiled they must be compiled for each platform you intend to run them on.

> **Interpreted** languages are not compiled to binary and instead are *'compiled'* at run time. They require an interpreter to be installed in order to execute their code. Because of this interpreted languages tend to be slower. However, because they can run on any platform that its interpreter is they tend to be very portable.

---

## C Files
See [files.md](./files.md).

---

## C Syntax
See [syntax.md](./syntax.md).

---

## C vs Assembly
Here we will see an example of a simple c program and it's compiled assembly representation. *C source code is generally very close to the final assembled version.*

- The example uses the `write()` function from `<unistd.h>`. Below is an explanation of it parameters.
    - `ssize_t write(int fildes, const void *buf, size_t nbyte);`
        - `ssize_t` Returns a signed integer
        - `int fildes` File descriptor to write to
        - `const void *buff` Address of a buffer to write
        - `size_t nbyte` Number of bytes to write

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

