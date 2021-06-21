//指針陣列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int (*q)[3] = arr; //類型(type) int[3]; 陣列指針[3]要跟arr相等
int main()
{

    int i,j,k;
    char *name[5] = {"hello world!","zhangsan","lizi","wangwu","zhaoliu"};
    char *tmp;

    //選擇排序
    for ( i = 0; i < 5-1; i++)
    {
        k = i;
        for ( j = i+1; j < 5; j++)
        {
            if(strcmp(name[k],name[j]) > 0)
            k = j;
        }
        if (k != i)
        {
            tmp = name[i];
            name[i] = name[k];
            name[k] = tmp;
        }
    }
    

    for ( i = 0; i < 5; i++)
    {
        printf("%s\n", name[i]);
    }
    
    exit(0);
}