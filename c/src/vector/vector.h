#ifndef TRNG_VECTOR_H
#define TRNG_VECTOR_H

#define VEC_ADD_TO(v1, v2) v1 = vec2_add(v1, v2);
#define VEC_SUB_TO(v1, v2) v1 = vec2_sub(v1, v2); 

typedef struct 
{
    double x, y;
} Vector2;

Vector2 vec2_add(Vector2 v1, Vector2 v2);
Vector2 vec2_sub(Vector2 v1, Vector2 v2);

#endif