#include <stdio.h>

// float clamp(float min, float max, float value);

int main(void)
{
    // Declare a float value to clamp
    float my_float = 3.75f; //

    printf("Hello world!\n");

    // Call out clamp function and store its return value in a new variable
    float clamped_value = clamp(1.0f, 2.0f, my_float);
    
    // Print out our results
    printf("%.2f clamped is %.2f\n", my_float, clamped_value);
    // %.2f means to print a float with 2 decimal places
    return 0;
}

float clamp(float min, float max, float value)
{
    if (value < min)
        return min; // Recall we do not require a code block { } if we only have 1 statement.
    
    if (value > max)
        return max;
    
    return value; // Our value is not too small or too big so we return it.
}