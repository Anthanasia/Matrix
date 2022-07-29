#include <stdio.h>
#include "matrix.h"

int main(void)
{
    matrix m = Init();
    double t;
    add(m, 2, 1, 3, 0, 5);
    t = trace(m);
    printf("%lf", t);
    return (0);
}