#include <stdio.h>
#include "vector.h"

int main(void)
{
    Vector2 vec1 = { 2.5, 3.5 };
    Vector2 vec2 = { 4.25, -1.3 };

    VEC_ADD_TO(vec1, vec2);

    printf("vec1 x: %.2f, y: %.2f\n", vec1.x, vec1.y);

    return 0;
}