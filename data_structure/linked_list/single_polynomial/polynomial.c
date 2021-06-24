#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

node *poly_create()
{
    node *me;
    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;
    me->next = NULL;
    return me;
}

node *poly_insert(node *me, int arr[][2], int n)
{
    int i;
    node *current, *newnode;
    current = me;
    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(*newnode));
        if (newnode == NULL)
            return NULL;
        newnode->coefficient = arr[i][0];
        newnode->exponent = arr[i][1];
        newnode->next = NULL;

        current->next = newnode;
        current = newnode;
    }
    return me;
}

void poly_show(node *me)
{
    node *current;
    for (current = me->next; current != NULL; current = current->next)
    {
        printf("(%d,%d) ", current->coefficient, current->exponent);
    }
    printf("\n");
}

void poly_union(node *p1, node *p2)
{
    node *node1, *node2, *node3;

    node1 = p1->next;
    node2 = p2->next;
    node3 = p1;

    while (node1 && node2)
    {
        if (node1->exponent < node2->exponent)
        {
            node3->next = node1;
            node3 = node1;
            node1 = node1->next;
        }
        else if (node1->exponent > node2->exponent)
        {
            node3->next = node2;
            node3 = node2;
            node2 = node2->next;
        }
        else //node1->exponent == node2->exponent
        {
            node1->coefficient += node2->coefficient;
            if (node1->coefficient)
            {
                node3->next = node1;
                node3 = node1;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    }

    if (node1 == NULL)
        node3->next = node2; //node1(p1)先結束(node1)p2剩下的全連上;
    else                     //node2==NULL
        node3->next = node1; //node2(p2)先結束(node1)p1剩下的全連上;
}