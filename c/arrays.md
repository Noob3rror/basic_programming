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
## Multi-Dimensional Array