#include <stdio.h>
#include <stdlib.h>

#define N 10

static void sort()
{
    int i, j, k, tmp;
    int a[N] = {23, 26, 98, 33, 2, 7, 32, 88, 6, 9};

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < sizeof(a) / sizeof(a[0]) - 1; i++)
    {
        k = i;
        for (j = i + 1; j < sizeof(a) / sizeof(a[0]); j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        if (i != k)
        {
            tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
        }
    }

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    sort();
}