#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int* arr = (int*)malloc(5 * sizeof(int));

    for (size_t i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}