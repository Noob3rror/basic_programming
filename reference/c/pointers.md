# Pointers
## What is a Pointer
- A pointer is a variable that stores the memory address of another variable.
- A pointer can point to another pointer. Called a double pointer.
    - In fact you can have pointers to pointers to pointers and so on. Tho you rarely see more than a double pointer.
## Syntax
- A pointer is defined by appending a `*` to a type.
- The `&` character while give you the memory address of a variable.
```c
int value = 1;
int* ptr; // declare our pointer to an `int`
// int * ptr; and int *ptr; are also valid syntax
ptr = &value; // get the address of `value` and assign it to `ptr`
```
- You can get the value stored at an address (pointer) by dereferencing it with `*`.
```c
printf("The value is %d\n", *ptr); // `&ptr` is like saying go get the value stored at the address in `ptr`
```
- The `&` operator when used on a pointer works the same as on a regular variable. It will give you the address of where the pointer's data is stored.
## Pointer Arithmetic
- You can perform math on a pointer just like any other value. Addition and subtraction are most relevant tho.
    - The data stored in a pointer is just a value that happens to be an address.
- Copying a pointer before performing operations on it is safer and should be done particulary when the pointer is pointing at memory that will need to be freed.
```c
#include <stdlib.h> // Include the malloc() function

#define VALUE_SIZE 5
// Allocate memory for 5 ints 
int* values = (int*)malloc(VALUE_SIZE * sizeof(int));
// Be sure to error check for malloc in real code

values[0] = 1; // you can treat a pointer just like an array

*(ptr + 1) = 3; // or use pointer arithmetic

// here ptr will be an address, lets say 0x0020
// + 1 means to add 1 sizeof(int) (4 bytes) since our pointer is an int pointer
// so it would be 0x0020 + 0x0004 = 0x0024
// 0x0024 is the address of the next int in our `values` variable
// we wrap ptr + 1 in ( ) so that the addition happens first
// then we dereference with * to tell the computer we are assigning 3
// to the value stored at the address of 0x0002 

free(values); // always free allocated memory
```
### Examples
- Examples will reference this code.
```c
int arr[10] = {0}; // create an array containing 10 ints all set to 0
// Keep in mind that arrays are also pointers under the hood.
```
#### Increment and Decrement
```c
int* ptr = arr; // store the address of arr; specifically the address of the first element
ptr++; // move the ptr to the next int (arr[1]); adds sizeof(int) bytes
ptr--; // move the ptr to the previous int (arr[0])
```
#### Addition and Subtraction
```c
int* ptr = arr;
ptr = ptr + 3; // set ptr to arr[3]
ptr -= 2;      // set ptr to arr[1] 
```
#### Pointer Difference
    - Find the number of **elements** between two pointers
```c
int* ptr1 = &arr[7];
int* ptr2 = &arr[2];
int diff = p1 - p2; // diff == 5
```
#### Dereference with Offset
    - Access a value at a specific offset without changing the pointer.
```c
int value = *(ptr + 3);
```
#### Array Traversal
```c
int* ptr = arr;
for (int i = 0; i < 10; i++)
{
    printf("%d\n", *(p + i));
}
```
#### Byte Level Access
```c
int value = 0xDEADBEEF;
unsigned char* byte_ptr = (unsigned char*)&value; // Get the address of value but treat it as an unsigned char address instead of an int address.
// Addresses are always the same size 32-bits on a 32-bit system, 64-bits on a 64-bit system
// But the compiler needs to associate a type to the address (that how adding 1 to an int pointer will move it 4 bytes and not 1 byte)

printf("First byte %02x\n", *byte_ptr);
// prints: First byte 0xDE 
// or
// First byte 0xEF
// depending on the endianness of your system 
```
## The void Pointer
- A void pointer is effectively typeless and cannot having pointer arithmetic performed on it.
- The `void*` pointer does allow a certain level of generic typing in C.
    - `malloc()` is a perfect example of the use of a void pointer.
```c
// malloc() just allocates x number of bytes
// by returning a void* it leaves the typing specification up to the user
// if it didn't do that you would need a malloc function for every possible type

void* void_ptr = malloc(2); // allocate 2 bytes
// We can cast the returned value to specific type pointer or as in this case leave it as a void*

// Then cast it to any type that could fit in the number of bytes allocated
short* short_ptr = (short*)void_ptr; // 1 short (2 bytes)
*short_ptr = 0xABBA;

char* char_array_ptr = (char*)void_ptr; // 2 chars (2 bytes)
// char_arr_ptr[0] == 0xAB
// char_arr_ptr[1] == 0xBA
```
***With the exception of a char pointer accessing memory via a different type than it was written with can lead to undefined behavior and subtle bugs.***

- You can use void* for your function parameters.
