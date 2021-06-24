#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"

//二級傳參
int list_insert(node **me, datatype *data)
{
    node *new;
    
    new = malloc(sizeof(*new));
    if (new == NULL)
        return -1;

    new->data = *data;
    // new->next = NULL;//馬上用可省略
    new->next = *me;
    *me = new;

    return 0;
}

//一級傳參(不建議)
// node * list_insert(node *me, datatype *data)
// {
//     node *new;
    
//     new = malloc(sizeof(*new));
//     if (new == NULL)
//         return NULL;

//     new->data = *data;
//     // new->next = NULL;//馬上用可省略
//     new->next = me;
//     me = new;

//     return me;
// }

void list_show(node *me)
{
    node *current;
    for (current = me; current != NULL; current = current->next)
    {
        printf("%d %s %d %d\n", current->data.id, current->data.name, current->data.math, current->data.english);
    }
}

int list_delete(node **me)
{
    node *current;
    if(*me == NULL)
        return -1;
    current = *me;
    *me = (*me)->next;
    free(current);
    return 0;
}

// int list_find(node *me, int id)
datatype * list_find(node *me, int id)
{
    node *current;
    for (current = me; current != NULL; current = current->next)
    {
        if(current->data.id == id)
        {
            //不建議直接printf
            // printf("%d %s %d %d\n",current->data.id, current->data.name, current->data.math, current->data.english);
            // return 0;
            //給用戶自己決定返回指針
            return &current->data;

        }
    }
    // return -1;
    return NULL;
}

void list_destroy(node * me)
{
    node *current;
    if(me == NULL)
        return;
    for (current = me; current != NULL; current = me)
    {
        me = current->next;
        free(current);
    }
    

}