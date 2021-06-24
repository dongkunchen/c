#include <stdio.h>
#include <stdlib.h>

#include "josephus.h"

node *jose_insert(int n)
{
    node *me, *newnode, *current;
    int i = 1;
    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;
    me->data = i;
    me->next = me;
    i++;

    current = me;
    for (; i <= n; i++)
    {
        newnode = malloc(sizeof(*newnode));
        if (newnode == NULL)
            return NULL;
        newnode->data = i;
        newnode->next = me;
        current->next = newnode;
        current = newnode;
    }
    return me;
}

void jose_show(node *me)
{
    node *currect;
    for (currect = me; currect->next != me; currect = currect->next)
    {
        printf("%d ", currect->data);
    }
    printf("%d\n", currect->data);
}

void jose_kill(node **me, int n)
{
    node *current = *me, *node;
    int i = 1;
    printf("依序淘汰的數字是 ");
    while (current != current->next)
    {
        while (i < n)
        {
            node = current;
            current = current->next;
            i++;
        }
        printf("%d ", current->data);
        node->next = current->next;
        free(current);

        current = node->next;
        i = 1;
    }
    *me = current;
    printf("\n");
}
