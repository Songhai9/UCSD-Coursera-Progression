#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

long long FindMaxProductFast(long long array[], int n)
{
    int max_index1 = -1;
    int max_index2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (max_index1 == -1 || array[i] > array[max_index1])
            max_index1 = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != max_index1 && (max_index2 == -1 || array[i] > array[max_index2]))
            max_index2 = i;
    }

    return array[max_index1] * array[max_index2];
}

int main()
{
    long long n;
    scanf("%lld", &n);

    long long A[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &A[i]);
    printf("\n");

    printf("%lld\n", FindMaxProductFast(A, n));

    return 0;
}