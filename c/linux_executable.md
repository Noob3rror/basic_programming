
# Program In Memory - linux
| Addr | Section | Desc |
|------|---------|------|
|0xFFFFFFFF| OS Kernel Space | Read and write protected from User Space |
|0xC0000000| | |
|0xBFFFFFFF| Stack | Contains local variables, caller's return address, etc|
|...| ▼ Stack grows downward ▼ | |
|...| | |
|...| ▲ Heap grows upward ▲ | |
|...| Heap | Dynamic memory allocations |
|...| BSS | Uninitialized static variables (all zeros) |
|...| Data | Explicitly initialized static variables |
|...| Text | The executable instructions of the program |
|0x08048000| End of process memory | |
|...| The rest of User mode memory | | 