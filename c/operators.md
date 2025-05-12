## Arithmetic Operators
|Symbol|Meaning|
|---|-|
|`+`| Addition |
|`-`| Subtraction |
|`*`| Multiplication |
|`/`| Division |
|`%`| Modulus (remainder) |

## Increment / Decrement
|Symbol|Meaning|
|---|-|
|`++`|	Increment by 1|
|`--`|	Decrement by 1|
- These operators can be prepended or appended to variables. (ie pre-increment / post-increment)
    - `--my_value` / `my_value--`
- If you prepend the operator it will increment/decrement the variable first then use the result in whatever operation. If you append it will use the variable first then increment/decrement the value.
```c
int i = 5;
int a = ++i; // pre-increment: i (5) becomes 6 then is assigned to a
int b = i++; // post-increment: i (6) is assigned to b; then i becomes 7
// i == 7
// a == 6
// b == 6
```

## Relational (Comparison) Operators
|Symbol|Meaning|
|---|-|
|`==`|    Equal to|
|`!=`|    Not equal to|
|`>`|	    Greater than|
|`<`|	    Less than|
|`>=`|    Greater than or equal|
|`<=`|    Less than or equal|

## Logical Operators
|Symbol|Meaning|
|---|-|
|`&&`| Logical AND|
|`\|\|`| Logical OR|
|`!`|  Logical NOT|

## Bitwise Operators
|Symbol|Meaning|
|---|-|
|`&`| Bitwise AND|
|`\|`| Bitwise OR|
|`^`| Bitwise XOR|
|`~`| Bitwise NOT|
|`<<`| Left shift|
|`>>`| Right shift|

## Assignment Operators
|Symbol|Meaning|
|---|-|
|`=`|	Assign|
|`+=`|	Add and assign|
|`-=`|	Subtract and assign|
|`*=`|	Multiply and assign|
|`/=`|	Divide and assign|
|`%=`|	Modulus and assign|
|`&=`|	Bitwise AND and assign|
|`\|=`| bitwise or and assign|
|`^=`|	Bitwise XOR and assign|
|`<<=`|	Left shift and assign|
|`>>=`|	Right shift and assign|

## Other Common Operators
|Symbol|Meaning|
|---|-|
|`sizeof`|	Size of a data type or variable|
|`&`|	Address-of (when prepended to a variable)|
|`*`|	Dereference pointer (when prepended to a variable)|
|`->`|	Access struct member via pointer|
|`.`|	Access struct member|
|`[]`|	Array subscript|
|`()`|	Function call|
|`,`|	Comma operator|
|`?:`|	Ternary (conditional) operator|
- Ternary explained
    - `condition` `?` `value if true` `:` `value if false` `;` 
    ```c
    int* ptr = NULL;
    int is_null = ptr == NULL ? 1 : 0;
    //         if (ptr == NULL) then 1 else 0
    // Kind of like a compact if else statement
    
    int is_null;
    
    if (ptr == NULL)
    {
        is_null = 1;
    }
    else
    {
        is_null = 0;
    }
    ```