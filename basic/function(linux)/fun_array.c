#include <stdio.h>
#include <stdlib.h>

void print_arr(int *p,int n)//sizeof(p) = 8
// void print_arr(int p[],int n)//sizeof(p)一樣 8只能用在形參
{
    int i;
    printf("%s:%d\n",__FUNCTION__,sizeof(p));

    for ( i = 0; i < n; i++)
        printf("%d ", *(p+i));
    printf("\n");
    
}

int main()
{
    int arr[] = {2,5,8,10,12};

    printf("%s:%d\n",__FUNCTION__,sizeof(arr));
    print_arr(arr,sizeof(arr)/sizeof(*arr));

    exit(0);
}