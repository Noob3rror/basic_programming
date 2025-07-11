#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LINE_BUFFER_SIZE 256
#define NO_ERROR 0
#define ERROR 1

int compressStdIn()
{
    int status = NO_ERROR;

    // Allocate a buffer to store each line of stdin
    char* lineBuffer = NULL;

    if ((lineBuffer = (char*)malloc(LINE_BUFFER_SIZE * sizeof(char))) == NULL)
    {
        perror("calloc");
        status = ERROR;
        goto CLEANUP;
    }

    size_t lineNumber = 0;

    while (fgets(lineBuffer, LINE_BUFFER_SIZE, stdin))
    {
        lineNumber++;

        // Replace the newline character with null terminator
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        // Convert string to unsigned long and validate
        errno = 0;
        char* endptr = NULL;
        unsigned long value = strtoul(lineBuffer, &endptr, 10);

        if (errno == ERANGE || value > UINT32_MAX)
        {
            fprintf(stderr, "Value out of range: %s on line %zu\n", lineBuffer, lineNumber);
            status = ERROR;
            goto CLEANUP;
        }

        if (endptr == lineBuffer || *endptr != '\0')
        {
            fprintf(stderr, "Invalid number: %s on line %zu\n", lineBuffer, lineNumber);
            status = ERROR;
            goto CLEANUP;
        }

        // Compress and output each value to stdout
        for (int i = 3; i >= 0; i--)
        {
            if (i == 0 || value >> 8 * i != 0)
            {
                size_t written = 0;

                written = fwrite(&i, sizeof(uint8_t), 1, stdout);
                written = fwrite((uint8_t*)&value, sizeof(uint8_t), i + 1, stdout);

                break;
            }
        }
    }

CLEANUP:

    free(lineBuffer);

    return status;
}

int main(int argc, char** argv)
{
    if (compressStdIn() != NO_ERROR)
    {
        //failed
        goto CLEANUP;
    }

CLEANUP:

    return 0;
}