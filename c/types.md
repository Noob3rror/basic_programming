# C Value Types
- [Standard Types](#standard-types)
    - [void](#void)
    - [char](#char)
    - [short](#short)
    - [int](#int)
    - [long](#long)
    - [long long](#long-long)
    - [float](#float)
    - [double](#double)
    - [signed](#signed)
    - [unsigned](#unsigned)
- [Twos Complement](#twos-complement) *(How negative numbers work)*
- [Floating Point](#floating-point-representation) *(How floating point numbers work)*
- [Extended Integer Types](#extended-integer-types) *<stdint.h>*
    - [Fixed-Width](#fixed-width-integer-types)
    - [Minimum-Width](#minimum-width-integer-types)
## Standard Types
### void
- The NULL type, effectively meaning no/unknown type.
- Most used to mark a function that does not return a value.
- A void pointer (void*) is returned by some functions like `malloc()` which is manually cast to the appropriate type by the caller. `int* int_ptr = (int*)malloc(5 * sizeof(int));`
### char
- 8 bit integer
- Signed by default.
- Generally used to store an ASCII character.
### short
- 16 bit integer.
- Signed by default.
- This is the size used for network ports (0 - 65535)
### int
- 32 bit integer.
- Signed by default.
- By convention the `main()` function should always return the `int` type.
- Unsigned suffix = `u` or `U`
### long
- 32 or 64 bit integer depending on platform and compiler.
- Signed by default.
- Suffix = `l` or `L`
- Unsigned suffix = `ul` or `UL`
### long long
- 64 bit integer.
- Signed by default.
- Suffix = `ll` or `LL`
- Unsigned Suffix = `ull` or `ULL`
### float
- A 32 bit precision floating point number.
- Always signed.
- Suffix = `f`
- `float my_float = 3.14f;`
### double
- A 64 bit precision floating point number.
- Always signed.
- No suffix.
    - long double is possible
    - Suffix = `L`
- `double my_double = 3.4556234445;`
### signed
- Used to specifically declare an integer type as holding a negative or positive value.
- Compilers generally assume this and thus `signed` can be omitted.
- `signed int my_int = 42;`
### unsigned
- Used to declare an integer type as containing only positive values.
- Also used as shorthand on its own for `unsigned int`
- `unsigned short my_ushort = 45;`
- `unsigned long long my_ulonglong = 123456789ULL;`
- `unsigned my_uint = 32;`

***Note: Suffixes on literals (explicit value like 32, 16.5, 0xAC01) act as hints to the compiler as well as to humans as to the intended size of a value. I always use them with floats.***

## Twos-Complement
Used to represent negative numbers in binary.
- The left most bit is used to represent the negative sign `-`
- Example
    - Start with the positive representation (`5`) = `00000101`
    - Invert each bit                            = `11111010`
    - Add 1                                      = `11111011`
    - `11111011` = `-5`

## Floating-Point Representation
The IEEE 754 single/double precision (`float`/`double`)

`float`
|Bit 0|Bits 1 - 8| Bits 9 - 31|
|-|-|-|
|Sign bit 1 = negative| Exponent | Mantissa (fraction) |

`double`
|Bit 0|Bits 1 - 11| Bits 12 - 63|
|-|-|-|
|Sign bit 1 = negative| Exponent | Mantissa (fraction) |

#### The **exponent** is stored with a bias.
- 127 for `float`
- 1023 for `double`

#### Example `float` for 6.5
- Binary `110.1` => `1.101 x 2^2` (Like scientific notation in decimal 1.5 x 10^2 = 150)
- Sign bit = `0`
- Exponent = `2 + 127` = 129 -> `10000001`
- Mantissa = `10100000000000000000000`
    - Note the leading 1 is dropped as it is implied.
        - 1.101 -> 101
    - This allows for an additional bit of accuracy.
- Final representation = `0 10000001 10100000000000000000000`



## Extended Integer Types
### <stdint.h>
Provides a standard library of fixed-width integer types. Useful for writing portable code across different platforms since the integer types listed above are not always guaranteed to be the same size in bytes everywhere.

### Fixed-width integer types
Guaranteed to be the size specified.

| Signed | Unsigned | | Equivalent |
|-|-|-|-|
| `int8_t` | `uint8_t` | | `char`/`unsigned char` |
| `int16_t` | `uint16_t` | | `short`/`unsigned short` |
| `int32_t` | `uint32_t` | | `int`/`unsigned`/`unsigned int` |
| `int64_t` | `uint64_t` | | `long` `long long`/ `unsigned long` `unsigned long long` |

### Minimum-width integer types
Guaranteed to be at least the specified size but may be larger.

| Signed | Unsigned | 
|-|-|
| `int_least8_t` | `uint_least8_t` | 
| `int_least16_t` | `uint_least16_t` | 
| `int_least32_t` | `uint_least32_t` | 
| `int64_least_t` | `uint_least64_t` | 

***<stdint.h> contains many more types as well as other features used to work with those types.***
