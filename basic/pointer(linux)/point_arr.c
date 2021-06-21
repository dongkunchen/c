//指針與陣列
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3] = {1,2,3};
    int *p = arr;
    int i;

    // p: address--variable arr: array--constant
    // a++; a = a + 1 //Constants cannot be used as lvalues
   
    p++;//p+1 != p++

    // a[i]: a[i] = *(a+i) =*(p+i) = p[i]
    // &a[i]: &a[i] = a+i = p+i = &p[i]

    printf("%p,%p\n",arr,arr+1);
    printf("%p,%p\n",p,p+1);

    // for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    for ( i = 0; i < sizeof(arr)/sizeof(*arr); i++)
        // printf("%p -> %d\n",&arr[i], arr[i]);
        printf("%p -> %d\n",arr+i, arr[i]);//i表示偏移i個int字節大小
        // printf("%p -> %d\n", p+i, arr[i]);
        // printf("%p -> %d\n", p+i, *(p+i));
    printf("\n");

    exit(0);
    
}