#include "vector.h"

// Returns the sum of two Vector2
Vector2 vec2_add(Vector2 v1, Vector2 v2)
{
    Vector2 result;

    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}

// Returns the difference of two Vector2
Vector2 vec2_sub(Vector2 v1, Vector2 v2)
{
    Vector2 result;

    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;

    return result;
}