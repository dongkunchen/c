//順序存儲模擬stack
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
    datatype arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    stack *st;
    int i;

    st = st_create();
    if (st == NULL)
        exit(1);
    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        st_push(st, &arr[i]); //入棧

    st_travel(st);

    // int ret;
    // datatype tmp = 70;
    // ret = st_push(st,&tmp);
    // if(ret == -1)
    //     printf("stack is full!\n");
    

    datatype tmp;
    while (st_pop(st, &tmp) == 0)
    {
        printf("%d 以出棧!\n", tmp);//出棧
    }

    st_destroy(st);

    return 0;
}