//Josephus Problem
#include <stdio.h>
#include <stdlib.h>

#include "josephus.h"

int main()
{
    node *list;

    list = jose_insert(JOSE_NUM);
    if (list == NULL)
        exit(1);
    
    jose_show(list);

    jose_kill(&list,JOSE_KILL);

    printf("最後剩下的數字是 ");
    jose_show(list);

    return 0;
}