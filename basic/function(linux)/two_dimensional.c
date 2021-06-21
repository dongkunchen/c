#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 4

void print_arr(int (*p)[C],int r, int c)
// void print_arr(int p[][C],int r, int c)
{
    int i,j;
    printf("sizeof(p) = %d\n", sizeof(p));

    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
            printf("%5d ", *(*(p+i)+j));
            // printf("%5d ", p[i][j]);
        printf("\n");
    }
    
}

void print_arr1(int *p,int n)//當成一維數組
{
    int i;
    for ( i = 0; i < n; i++)
        printf("%2d ", p[i]);
    printf("\n");
}

int main()
{
    int arr[R][C] = {1,5,6,7,8,9,3,2,4,10,11,12};
    int i,j;

    printf("sizeof(arr) = ", sizeof(arr));

    print_arr(arr,R,C);
    print_arr1(*arr,R*C);
    // for ( i = 0; i < R; i++)
    // {
    //     for ( j = 0; j < C; j++)
    //     {
    //         printf("%5d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    
    exit(0);
}