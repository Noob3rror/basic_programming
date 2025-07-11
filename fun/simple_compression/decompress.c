#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define NO_ERROR 0
#define ERROR 1

int decompressStdIn()
{
    int status = NO_ERROR;
    int sizeByte = 0;

    while ((sizeByte = fgetc(stdin)) != EOF)
    {
        uint32_t combined = 0;

        for (size_t i = 0; i <= sizeByte; i++)
        {
            combined |= fgetc(stdin) << 8 * i;
        }

        fprintf(stdout, "%" PRIu32, combined);

        int nextByte = fgetc(stdin);
        
        if (nextByte != EOF)
        {
            fprintf(stdout, "\n");
        }

        ungetc(nextByte, stdin);
    }

CLEANUP:

    return status;
}

int main(int argc, char** argv)
{
    if (decompressStdIn() != NO_ERROR)
    {
        //failed
        goto CLEANUP;
    }

CLEANUP:

    return 0;
}