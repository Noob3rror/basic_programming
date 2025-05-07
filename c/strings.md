# Strings
char str[] = "Hello";

This is stored in memory like:

'H' 'e' 'l' 'l' 'o' '\0'

You can also define it manually:

char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};

char name[10] = "Alice"; // copies the literal into writable memory
char *name = "Alice"; // points to the readonly data of the exe

string literals immutable

## string.h
strlen(str)	Length of the string (excluding '\0)
strcpy(dest, src)	Copies string from src to dest
strcat(dest, src)	Appends src to end of dest
strcmp(s1, s2)	Compares two strings
strchr(str, c)	Finds first occurrence of c