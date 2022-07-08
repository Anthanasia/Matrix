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

int left_digit(int n)
{
return (n / 10);
}

void print_number(int n)
{
int a;
int i = 0;
if (n < 0)
{
n = -n;
_putchar('-');
}
if (n >= 10)
{
while (n >= 10)
{
a = n;
while (a >= 10)
{
a = left_digit(a);
i++;
}
_putchar(a + '0');
while (i > 0)
{
a = a * 10;
i--;
}
n = n - a;
}
_putchar(n + '0');
}
else
{
if (n < 10)
{
_putchar(n + '0');
}
else
{
_putchar(n + '0');
}
}
}


int main(void)
{
    print_number(98);
    _putchar('\n');
    print_number(402);
    _putchar('\n');
    print_number(1024);
    _putchar('\n');
    print_number(0);
    _putchar('\n');
    print_number(-98);
    _putchar('\n');
    return (0);
}
