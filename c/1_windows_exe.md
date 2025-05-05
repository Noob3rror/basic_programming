# Windows EXE 
## DOS Header
- **Signature Field**
    - Always 0x5A4D "MZ" - indicates the file is executable
- **Pointer to PE Header**
    - Offset to the PE header from the beginning of file

| Addr |  Bytes | Description |
|------|--------|--------|
|0x0000| **4D 5A** 90 00 03 00 00 00 | Signature Field "MZ" | 
|0x0008| ... | |
|0x0038| 00 00 00 00 **80 00 00 00** | Pointer to PE Header |
## DOS Stub
Code to run if in a DOS environment. Typically prints "This program cannot be run in DOS mode"

| Addr |  Bytes | Description |
|------|--------|--------|
|0x0040| ... | |

## PE Header
- **PE Signature Field**
    - Always 0x00004550 "PE\0\0"
- **Machine**
    - Architecture ie 0x8664 (32/64 bit)
        - *0x014C -> Intel 386 (32-bit)*
        - *0x8664 -> AMD 64 (64-bit)*
        - *0x01C0 -> ARM (32-bit)*
        - *0xAA64 -> ARM64*
- **NumberOfSections**
    - How many sections there are
- **TimeDateStamp**
    - Build timestamp
- **SizeOfOptionalHeader**
    - Size in bytes of the optional header
- **Characteristics**
    - Bit flags indicating properties such as DLL, executable, etc

| Addr |  Bytes | Description |
|------|--------|--------|
|0x0080| **50 45 00 00** 4C 01 **0F 00** | **Signature "PE\0\0"**, Machine, **NumberOfSections** |
|0x0088| **86 3D 8D 66** 00 D4 06 00 | **TimeDateStamp**, PointerToSymbolTable |
|0x0090| **0C 07 00 00** E0 00 **07 01** | **NumberOfSymbolTable**, SizeOfOptionalHeader, **Characteristics** |

## Optional Headers
- **Windows Specific Fields**
    - Go research it
- **Data Directories**
    - Go research it

## Section Table
- **Name**
    - Section name, 8-byte string
        - .text -> executable code
        - .data -> Initialized global/static variables
        - .rdata -> read-only data (strings, imports etc)
        - .bss -> unitialized data
        - .rsrc -> icons, images, etc
        - .reloc -> Base relocations for ASLR (Address Space Layout Randomization)
- **VirtualSize**
- **VirtualAddress**
    - Location to load into memory
- **SizeOfRawData**
    - Size of section
- **PointerToRawData**
    - Offset to section data
- **PointerToRelocations**
- **PointerToLineNumbers**
- **NumberOfRelocations**
- **NumberOfLineNumbers**
- **Characteristics**




# DLLs (Dynamically Linked Libraries)


TODO


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