## Twos-Complement
Used to represent negative numbers in binary.

- The left most bit is used to represent the negative sign `-`
- Example
    - Start with the positive representation (`5`) = `00000101`
    - Invert each bit                            = `11111010`
    - Add 1                                      = `11111011`
    - `11111011` = `-5`
---
## Floating-Point Representation
The IEEE 754 single/double precision (`float`/`double`)

#### float

|Bit 0|Bits 1 - 8| Bits 9 - 31|
|-|-|-|
|Sign bit 1 = negative| Exponent | Mantissa (fraction) |

#### double

|Bit 0|Bits 1 - 11| Bits 12 - 63|
|-|-|-|
|Sign bit 1 = negative| Exponent | Mantissa (fraction) |

## Float Bias
The exponent is stored with a bias.

- 127 for `float`
- 1023 for `double`

#### Example `float` for the value 6.5
- Binary `110.1` => `1.101 x 2^2` (Like scientific notation in decimal 1.5 x 10^2 = 150)
- Sign bit = `0`
- Exponent = `2 + 127` = 129 -> `10000001`
- Mantissa = `10100000000000000000000`
    - Note the leading 1 is dropped as it is implied.
        - 1.101 -> 101
    - This allows for an additional bit of accuracy.
- Final representation = `0 10000001 10100000000000000000000`

## Endianness
TODO