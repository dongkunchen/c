#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {6,8,9,7,1,4};//a[0] = 6
    int y;
    int *p = &arr[1];

    y = (*--p)++;
    printf("y = %d\n", y);
    printf("arr[0] = %d\n", arr[0]);//a[0] = 7

    exit(0);
}