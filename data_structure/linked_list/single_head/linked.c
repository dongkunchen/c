#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

linked *linked_create()
{
    linked *me;
    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;
    me->next = NULL;
    return me;
}

int linked_insert_at(linked *me, int i, datatype *data)
{
    int j = 0;
    linked *node = me, *newnode;
    if (i < 0)
        return -1;
    while (j < i && node != NULL)
    {
        node = node->next;
        j++;
    }
    if (node)
    {
        newnode = malloc(sizeof(*newnode));
        if (newnode == NULL)
            return -2;
        newnode->data = *data;
        newnode->next = node->next;
        node->next = newnode;
        return 0;
    }
    else
        return -3;
}

int linked_insert_order(linked *me, datatype *data)
{
    linked *p = me, *q;
    while (p->next && p->next->data < *data)
        p = p->next;
    q = malloc(sizeof(*q));
    if (q == NULL)
        return -1;
    q->data = *data;
    q->next = p->next;
    p->next = q;
    return 0;
}

int linked_delete_at(linked *me, int i, datatype *data)
{
    int j = 0;
    linked *p = me,*q;
    *data = -1;
    if(i < 0)
        return -1;
    while(j < i && p)
    {
        p = p->next;
        j++;
    }
    if(p)
    {
        q = p->next;
        p->next = q->next;
        *data = q->data;
        free(q);
        q = NULL;
        return 0;
    }
    else
        return -2;
    
}

int linked_delete(linked *me, int num)
{
    linked *p = me, *q;
    while (p->next && p->next->data != num)
        p= p->next;
    if(p->next == NULL)
        return -1;
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
        q= NULL;
    }
}

int linked_isempty(linked *me)
{
    if (me->next == NULL)
        return 0;
    return 1;
}

void linked_display(linked *me)
{
    linked *node = me->next;
    if (linked_isempty(me) == 0)
        return;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void linked_destroy(linked *me)
{
    linked *node, *next;
    for (node = me->next; node != NULL; node = next)
    {
        next = node->next;
        free(node);
    }
    free(me);
}
