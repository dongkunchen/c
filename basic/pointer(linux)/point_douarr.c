//指針跟二維陣列
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[2][3] = {1,2,3,4,5,6};
    int i, j;
    int *p;
    int (*q)[3] = arr; //類型(type) int[3]; 數組指針[3]要跟arr相等

    p = &arr[0][0]; // *a  或 *(a+0);

    for ( i = 0; i < 6; i++)
       printf("%d ",p[i]);
    printf("\n");    
    

    printf("%p %p\n", arr, arr+1);
    printf("%p %p\n", q, q+1);

    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            // printf("%p ----> %d\n",&arr[i][j], arr[i][j]);
            // printf("%p ----> %d\n",*(arr+i)+j, *(*(arr+i)+j));
            printf("%p ----> %d\n",*(q+i)+j, *(*(q+i)+j));
        }        
        printf("\n");
    }
    


    exit(0);
}