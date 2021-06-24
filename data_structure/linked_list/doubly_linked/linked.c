#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked.h"

linked *linked_create(int initsize)
{
    linked *new;
    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;
    
    new->size = initsize;
    new->head.data = NULL;
    new->head.pre = &new->head;
    new->head.next = &new->head;

    return new;
}

int linked_insert(linked *ptr, const void *data, int mode)
{
    node *newnode;
    newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
        return -1;
    newnode->data = malloc(ptr->size);
    if (newnode->data == NULL)
        return -2;
    memcpy(newnode->data, data, ptr->size);

    if (mode == LINKED_FORWARD)
    {
        newnode->pre = &ptr->head;
        newnode->next = ptr->head.next;
    }
    else if (mode == LINKED_BACKWARD)
    {
        newnode->pre = ptr->head.pre;
        newnode->next = &ptr->head;
    }
    else
    {
        return -3;
    }
    newnode->pre->next = newnode;
    newnode->next->pre = newnode;

    return 0;
}

static node *find_(linked *ptr,const void *key,linked_cmp *cmp)
{
    node *current;
    for (current =ptr->head.next; current != &ptr->head; current=current->next)
    {
        if(cmp(key,current->data)==0)//假設數據沒重複,找一個找到返回
            break;
    }
    return current;
}

void *linked_find(linked *ptr,const void *key,linked_cmp *cmp)
{
    return find_(ptr,key,cmp)->data;//沒找到會等於head 空指針
}

int linked_delete(linked *ptr,const void *key,linked_cmp *cmp)
{
    node *node;
    node = find_(ptr,key,cmp);
    if (node == NULL)
        return -1;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    free(node->data);
    free(node);
    return 0;
}

int linked_fetch(linked *ptr,const void *key,linked_cmp *cmp,void *data)
{
    node *node;
    node = find_(ptr,key,cmp);
    if (node == NULL)
        return -1;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    if(data != NULL)
        memcpy(data,node->data,ptr->size);
    free(node->data);
    free(node);
    return 0;
}

void linked_travel(linked *ptr, linked_op *op)
{
    node *current;
    for (current = ptr->head.next; current != &ptr->head; current = current->next)
        op(current->data);
}

void linked_destroy(linked *ptr)
{
    node *current, *next;

    for (current = ptr->head.next; current != &ptr->head; current = next)
    {
        next = current->next;
        free(current->data);
        free(current);
    }
    free(ptr);
}