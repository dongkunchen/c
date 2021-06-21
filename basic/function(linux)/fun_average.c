#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 4

float fun_average(int *p, int n)
{
    int i;
    float sum;
    for (i = 0; i < n; i++)
    {
        sum += p[i];
    }
    return sum/n;
}

int main()
{
    int arr[R][C] = {1, 5, 6, 7, 8, 9, 3, 2, 4, 10, 11, 12};
    float avg;

    avg = fun_average(*arr, R * C);
    printf("avg=%f\n", avg);

    return 0;
}