#include <stdio.h>
#include <stdlib.h>

#define N 10

static void sort()
{
    int i, j, k, tmp;
    int arr[N] = {23, 26, 98, 33, 2, 7, 32, 88, 6, 9};

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        k = i;
        for (j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        if (i != k)
        {
            tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
        }
    }

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    sort();
}
