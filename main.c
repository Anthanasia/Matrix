#include <stdio.h>
#include "matrix.h"


#include <stdlib.h>
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

int _atoi(char *s)
{
    int i = 0, j = 0, nbre = 0, p = 0;
    char *n = malloc(sizeof(char));
    while (s[i] != '\0')
    {
        i++;
    }
    for (j = 0; j <= i; j++)
    {
        if (_putchar(s[j] + '0') < _putchar(48) || _putchar(s[j] + '0') > _putchar(57))
        {
            continue;
        }
        else
        {
            if (_putchar(s[j] + '0') <= _putchar(57) && _putchar(s[j] + '0') >= _putchar(48))
            {
                *(n + j) = *(s + j);
            }
        }
    }
    i = 0;
    while (n[i] != '\0')
    {
        i++;
    }
    for (j = 0; j <= i; j--)
    {
        nbre = nbre * 10 + _putchar(n[i] + '0');
    }
    free(n);
    if (p > 0)
    {
        nbre = -nbre;
    }
    return (nbre);
}

int main(void)
{
    int nb;

    nb = _atoi("98");/*
    printf("%d\n", nb);
    nb = _atoi("-402");
    printf("%d\n", nb);
    nb = _atoi("          ------++++++-----+++++--98");
    printf("%d\n", nb);
    nb = _atoi("214748364");
    printf("%d\n", nb);
    nb = _atoi("0");
    printf("%d\n", nb);
    nb = _atoi("Suite 402");
    printf("%d\n", nb);
    nb = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA    ");
    printf("%d\n", nb);
    nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
    printf("%d\n", nb);*/
    return (0);
}