#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 4

void find_row(int (*p)[C], int row)
{
    int i;
    for ( i = 0; i < C; i++)
    {
        printf("%3d ", *(*(p+row)+i));
    }
    printf("\n");
}

int main()
{
    int arr[R][C] = {1,5,6,7,8,9,3,2,4,10,11,12};
    int row = 1;

    find_row(arr,row);

    return 0;
}