#include <stdio.h>

int EuclidGCD(int a, int b)
{
    if (b == 0)
        return a;
    int r = a % b;
    return EuclidGCD(b, r);
}

int main()
{
    printf("%i\n", EuclidGCD(357, 234));

    return 0;
}