#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

int main()
{
    sqlist *list,*list1,*ret;
    datatype arr[] = {10, 20, 30, 40, 50};
    datatype arr1[] = {15, 25, 35, 45, 55};
    int i,err;
        // list = sqlist_create();
        // if(list == NULL)
        // {
        //     fprintf(stderr,"sqlist_create() failed!\n");
        //     exit(1);
        // }
    // sqlist_create1(&list);
    list = sqlist_create(&list);
    if (list == NULL)
    {
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);
    }
    
    list1 = sqlist_create();
    if (list1 == NULL)
    {
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);
    }

    // printf("%d\n",__LINE__);//打印行數可以調適bug打印出來就是這行之前沒問題
    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        if ((err=sqlist_insert(list, i, &arr[i])) != 0)//0會倒敘i會正敘
        {
            if(err == -1)
                fprintf(stderr, "The array is full.\n");
            else if(err == -2)
                fprintf(stderr, "The position you want to insert is wrong.\n");
            else 
                fprintf(stderr, "Error!\n");
            exit(1);
        }

    sqlist_display(list);

    
    for (i = 0; i < sizeof(arr1) / sizeof(*arr1); i++)
        if ((err=sqlist_insert(list1, i, &arr1[i])) != 0)//0會倒敘i會正敘
        {
            if(err == -1)
                fprintf(stderr, "The array is full.\n");
            else if(err == -2)
                fprintf(stderr, "The position you want to insert is wrong.\n");
            else 
                fprintf(stderr, "Error!\n");
            exit(1);
        }
    sqlist_display(list1);

    sqlist_union(list,list1);

    sqlist_display(list);

    // sqlist_delete(list,1);//按下標(0開始)找自己定義 操作手冊 用戶使用也可改(1開始)

    // sqlist_display(list);

    sqlist_destroy(list);
    sqlist_destroy(list1);

    return 0;
}