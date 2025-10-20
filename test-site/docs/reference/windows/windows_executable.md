# Windows EXE 
## PE Layout Image
![PE32STRUCTURE](../../images/pe32structure.png)
## DOS Header
| Addr |  Bytes | Description |
|------|--------|--------|
|0x0000| **4D 5A** 90 00 03 00 00 00 | Signature Field "MZ" | 
|0x0008| ... | |
|0x0038| 00 00 00 00 **80 00 00 00** | Pointer to PE Header |

#### Signature Field
Always `0x5A4D` (`"MZ"` in ASCII) - indicates the file is executable
#### Pointer to PE Header
Offset to the PE header from the beginning of file



## DOS Stub
Code to run if in a DOS environment. 

| Addr |  Bytes | Description |
|------|--------|--------|
|0x0040| ... | Typically prints "This program cannot be run in DOS mode" |

## PE Header

| Addr |  Bytes | Description |
|------|--------|--------|
|0x0080|<span class="nowrap"><span class="bg-text bg-a">50 45 00 00</span><span class="bg-text bg-b">4C 01</span><span class="bg-text bg-c">0F 00</span></span>|<span class="bg-text bg-a">PESignature</span><span class="bg-text bg-b">Machine</span><span class="bg-text bg-c">NumberOfSections</span>|
|0x0088|<span class="nowrap"><span class="bg-text bg-d">86 3D 8D 66</span><span class="bg-text bg-e">00 D4 06 00</span></span>|<span class="nowrap"><span class="bg-text bg-d">TimeDateStamp</span><span class="bg-text bg-e">PointerToSymbolTable</span></span>|
|0x0090|<span class="nowrap"><span class="bg-text bg-f">0C 07 00 00</span><span class="bg-text bg-g">E0 00</span><span class="bg-text bg-h">07 01</span></span>|<span class="bg-text bg-f">NumberOfSymbolTable</span><span class="bg-text bg-g">SizeOfOptionalHeader</span><span class="bg-text bg-h">Characteristics</span>|

#### <span class="bg-text bg-a">PESignature</span>
Always `0x00004550 "PE\0\0"`

#### <span class="bg-text bg-b">Machine</span>
Architecture of the machine, ie Intel, 32-bit, etc

| Bytes | Architecture |
| - | - |
| 0x014C | Intel 386 (32-bit) |
| 0x8664 | AMD 64 (64-bit) |
| 0x01C0 | ARM (32-bit) |
| 0xAA64 | ARM64 |

#### <span class="bg-text bg-c">NumberOfSections</span>
How many sections there are

#### <span class="bg-text bg-d">TimeDateStamp</span>
Build timestamp

#### <span class="bg-text bg-e">PointerToSymbolTable</span>
TODO

#### <span class="bg-text bg-f">NumberOfSymbolTable</span>
TODO

#### <span class="bg-text bg-g">SizeOfOptionalHeader</span>
Size in bytes of the optional header

#### <span class="bg-text bg-h">Characteristics</span>
Bit flags indicating properties such as DLL, executable, etc

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
