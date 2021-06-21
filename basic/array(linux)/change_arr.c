//行列互換
#include <stdio.h>
#include <stdlib.h>

#define M  2
#define N  3

int main()
{
    int a[M][N] = {1, 2, 3, 4, 5, 6}, b[N][M];
    int i, j;

    for (i = 0; i < M; i++)
    {
        for ( j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
            b[j][i] = a[i][j];
        }
        printf("\n");
    }

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < M; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    
    exit(0);
}