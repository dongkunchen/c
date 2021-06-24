//simulation function(CRUD)
#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"

int main()
{
    node *list = NULL;
    datatype tmp;
    int i,result;

    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.english = rand() % 100;
        result = list_insert(&list, &tmp);//二級傳參
        // list = list_insert(list, &tmp); //一級傳參
        if(result !=0)
            exit(1);
    }

    list_show(list);

    printf("-------------------\n");

    list_delete(&list);//頭部刪除

    list_show(list);

    printf("-------------------\n");

    // list_find(list,2);//id查找
    datatype *ptr;
    ptr = list_find(list,2);
    if(ptr==NULL)
        printf("Can not find!\n");
    else
      printf("%d %s %d %d\n",ptr->id, ptr->name, ptr->math, ptr->english);

    list_destroy(list);

    exit(0);
}