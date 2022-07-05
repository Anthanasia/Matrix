#include <stdio.h>
#include "matrix.h"


#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int main(){
int i,n;
for (i = n; i<=98; i++) {
    printf("%d, ", i);
}
printf("\n");
return 0;
}