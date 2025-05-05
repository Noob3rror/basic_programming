# Windows Process Memory Layout
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
|0x00000000| The rest of User mode memory | | 

***Note:*** *These regions are not necessarily physically next to one another particularly on modern OSs.*