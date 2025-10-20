# Memory Allocation
## Static
Memory that is allocated at compile time.
- Global variables
```c
int my_global = 100;
// Allocated at compile time and exists as 4 bytes reserved in the binary file itself
int main(void)
{
    // ...
}
```
## Automatic
Memory that is allocated on the stack.
- Local variables
```c
void my_function(void)
{
    // Automatic allocates sizeof(int) (usually 4) bytes on the stack.
    int my_local = 5;

    // Exiting the function causes it to be popped off the stack and automatically frees any allocated memory.
    return;
}
```
## Dynamic
Allocated at runtime using functions like `malloc()` or `calloc()` and manually freed with `free()`. Dynamically allocated memory lives in the heap.
```c
void my_function(void)
{
    // Allocates 5 * 4 bytes on the heap.
    int* my_dynamic = (int*)malloc(5 * sizeof(int));
    // int my_array[5]; is functionally equivalent but would be on the stack and not the heap.
}
```
### malloc
`void* malloc(size_t size);`
- Allocates memory on the heap. `size` specifies the number of bytes to allocate.
- Returns `void*` that should be cast to the appropriate type.
- The block of memory allocated will have whatever data that was left in RAM at that location.
    - Because of this it is possible to 'leak' data; so be sure to zero-initialize or assign your data.
- Returns `NULL` on failure.
```c
int* values = (int*)malloc(10 * sizeof(int)); // Allocates 10 `ints`
// Returns a pointer to the first int

// ALWAYS validate memory allocations
if (values == NULL)
{
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}
```
### calloc
`void* calloc(size_t num, size_t size);`
- Effectively the same as `malloc` with two differences.
    - Guarantees the memory allocated will be zero-initialized.
    - Provides 2 parameters for the number of elements and the size of an element.
- Returns `NULL` on failure.
```c
int* values = (int*)malloc(10, sizeof(int));

// ALWAYS validate memory allocations
if (values == NULL)
{
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}
```
### realloc
`void* realloc(void* ptr, size_t new_size);`
- Resizes the memory block pointed to by `ptr` to `new_size`.
- May move the location of the memory block if necessary; will return a `void*` pointer to the new location.
- Returns `NULL` on failure.
```c
// Assign the return value to a temporary pointer
// If you assign the return value to your original pointer
// and realloc fails your original pointer will be overwritten with NULL
// causing you to lose access to your original allocated memory
int* new_values = (int*)realloc(values, 20 * sizeof(int));

// ALWAYS validate memory allocations
if (new_values == NULL)
{
    // If a realloc fails your original pointer is still valid
    fprintf(stderr, "Failed to reallocate memory, can still safely use `values`\n");
}
else
{
    // realloc succeeded, you can assign the new memory location if there is one
    values = new_values;
}
```
### free
`void free(void* ptr);`
- Frees the memory block located at `ptr`.
- Always free memory that has been allocated. This is where memory leaks come from.
    - Technically the OS will free all memory for you when your program ends but this is rarely ideal.
```c
free(values);
```