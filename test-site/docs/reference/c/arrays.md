TODO
# Arrays
## Single-Dimensional Array
An array is a block of memory that stores a series of values of the specified type. Array elements are zero-indexed in C. Meaning you access the first element with `0` and the last element is `n - 1` (n is often used to mean the count/size of the array).
```c
int my_array[5];
```
- We specify the type `int` the label/name `my_array` the `[]` indicates that it is an array and `5` is the size or number of elements in the array.
- When we declare an array this way the elements of the array will have whatever values were in memory where the array is created. This is most often just `0s` but it could be any left over junk data.
```c
int my_array[5] = {0};
```
- Here we declare the array and initialize all values to `0`. You can only initialize to `0` so replacing the `0` above with `1` or `234` will cause a compiler error.
- If you need to initialize with a specific value (or to simply gurantee there is no junk data) we can manually assign values.
```c
int my_array[5];
my_array[0] = 1;
my_array[1] = 2;
...
my_array[4] = 5;
```
- Or use a loop.
```c
int my_array[5];
for (int i = 0; i < 5; i++)
{
    my_array[i] = 1; // assign all elements to the value 1
}
```
### Arrays Decay to Pointers
The array syntax under the hood is actually a pointer. Arrays *decay* to a pointer to i's first element.
```c
int my_array[5] = {1, 2, 3, 4, 5}; // the '5' in [] is optional when explicitly setting each element
int* p = my_array; // my_array decays to &my_array[0]; & here means 'address of'
```
- `my_array[i]` is equivalent to `*(my_array + i)`
- This can be seen with alternate array notation
```c
if (my_array[0] == 0[my_array])
{
    // This evaluates as true
    // my_array[0] -> *(my_array + 0)
    // 0[my_array] -> *(0 + my_array) == *(my_array + 0)
}
```
### When Arrays Do Not Decay
- `sizeof()`
```c
int my_array[5] = {1, 2, 3, 4, 5};
int* p = my_array;
sizeof(my_array); // size of the entire array (5 * sizeof(int))
sizeof(p); // size of a pointer
```
- `&` unary operator
```c
&my_array; // type is: int (*)[5]
&my_array[0]; // type is: int*
// The addresses of these two are the same but the types are not
```
## Multi-Dimensional Array
Multi-dimensional arrays are arrays of arrays. Most commonly 2D arrays which you can think of as rows and columns.
```c
#define ROWS 3
#define COLS 4

int matrix[ROWS][COLS];
// This creates a 3x4 2D array
```
- Full initialization
```c
int matrix[2][3] = {
    {1, 2, 3}, // two rows
    {4, 5, 6} // three columns
};
```
- Partial initialization
    - Unspecified elements are filled with `0`.
```c
int matrix[2][3] = { {1}, {4, 5} };
```
- Accessing elements
```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
int value = matrix[1][2]; // 2nd row, 3rd column; remember arrays are 0-indexed
```
### Looping over a 2D array
There are generally two approaches to looping over a multi-dimensional array.
- Nested `for` loops
```c
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```
- `i` and `j` are conventional names for these variables. `i` meaning index and then `j` because it is alphabetical. If you nest another `for` loop you would use `k` and so on.
    - You can also name them more relevant names like `row`, `col` or `x`, `y`.
- The second way to loop a multi-dimensional array relies on the fact that arrays are stored in memory in **row-major order**. Meaning each row is laid out one after the other in "1D" memory.
    - row-major order
    ```c
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    // 1, 2, 3, 4, 5, 6 in memory
    ```
- Loop any multi-dimensional array by casting to a 1D array
```c
// total size of the array divided by the size of one element => number of elements
int num_elements = sizeof(matrix) / sizeof(int); 

for (int i = 0; i < num_elements; i++)
{
    int value = ((int *)matrix)[i];
}
```
- You can even treat a 1D array as 2D
    - This is often useful when dealing with heap allocated arrays or raw byte data from a file.
```c
int my_array[6] = {1, 2, 3, 4, 5, 6};

int num_rows = 2;
int num_cols = 3;

for (int row = 0; row < num_rows; row++)
{
    for (int col = 0; col < num_cols; col++)
    {
        printf("%d ", my_array[row * num_cols + col]);
    }
    printf("\n");
}
```
## Cautions
- When you pass an array into a function it decays to a pointer so `sizeof(arr)` will no longer give you the full size of the array.
