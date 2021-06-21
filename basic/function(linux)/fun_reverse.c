#include <stdio.h>
#include <stdlib.h>

void func_reverse(int *p, int n)
{
    int i = 0,mid,j,tmp;

    mid = (n-1)/2;//middle

    for ( i = 0; i <= mid; i++)
    {
        j = n - 1 - i;//j : count down
        tmp = p[j];
        p[j] = p[i];
        p[i] = tmp;
    }
    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i;

    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        printf("%d ", arr[i]);
    printf("\n");

    func_reverse(arr,sizeof(arr)/ sizeof(*arr));

    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        printf("%d ", arr[i]);
    printf("\n");

    exit(0);
}