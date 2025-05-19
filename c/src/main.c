#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    int data;
    Node* next;
    /* data */
} Node;


/// @brief Create a new node
/// @param value 
/// @return Node or NULL
Node* new_node(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

/// @brief 
/// @param dest 
/// @param value 
void append_node(Node* dest, int value)
{
    if (!dest)
    {
        return;
    }

    Node* node = new_node(value);
    if (!node)
    {
        return;
    }

    Node* end = dest->next;
    while(end->next != NULL)
    {
        end = end->next;
    }

    end->next = node;
}


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