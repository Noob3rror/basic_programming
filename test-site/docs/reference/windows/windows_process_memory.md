# Windows Process Memory Layout
## Layout Table
| Addr | Regions | Desc |
|------|---------|------|
|0xFFFFFFFF| OS Kernel Space | Read and write protected from User Space |
|...| Reserved Space | Depends on OS / configuration |
|...| | |
|...| Stack | Local storage, function calls, caller's return address, etc |
|...| ▼ Stack grows downward ▼ | |
|...| ▲ Heap grows upward ▲ | |
|...| Heap | Dynamic memory allocations |
|...| Memory mapped files | DLLs, EXEs, shared memory, etc |
|...| Data | Global/static initialized variables |
|...| BSS |  Global/static uninitialized variables |
|...| Text | Executable code (read only) |
|...| PE Header | Image base address, DOS header, etc |
|...| | |
|0x00000000| The rest of User mode memory | | 

***Note:*** *These regions are not necessarily physically next to one another particularly on modern OSs.*
## Address Space Layout Randomization
ASLR randomizes the memory addresses where key parts of a program are loaded. This is a security feature intended to make it more difficult for attackers to take advantage of vulnerabilities like buffer overflows.

The follow are randomized by ASLR:
- Base addresses of loaded DLLs
- Stack location
- Heap location
- Address of the executable image
- Address of memory-mapped files

The layout changes each time the process is executed to prevent hardcoded address-based exploits.

**Executables and DLLs must be compiled with the `/DYNAMICBASE` flag to support ASLR on Windows.**