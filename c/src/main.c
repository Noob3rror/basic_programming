#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // int* arr = (int*)malloc(5 * sizeof(int));

    // for (size_t i = 0; i < 5; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    // free(arr);

    char* str1 = "hello";
    char str2[] = "hello";
    char* str3 = str2;
    if (str3 == str2) // The comparison made is actually comparing the pointers
    {
        printf("The strings are the same.\n");
    }


    return 0;
}