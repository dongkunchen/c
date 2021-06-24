#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked.h"

typedef struct linked_node_st
{
    struct linked_node_st *pre;
    struct linked_node_st *next;
    char data[1];
    
}node;

struct linked_head_st
{
    int size;
    struct linked_node_st head;
};

linked *linked_create(int initsize)
{
    struct linked_head_st *new;
    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;
    
    new->size = initsize;
    new->head.pre = &new->head;
    new->head.next = &new->head;

    return new;
}

int linked_insert(linked *p, const void *data, int mode)
{
    node *newnode;
    struct linked_head_st *ptr = p;

    newnode = malloc(sizeof(*newnode)+ptr->size);
    if (newnode == NULL)
        return -1;

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

static node *find_(struct linked_head_st *ptr,const void *key,linked_cmp *cmp)
{
    node *current;
    
    for (current =ptr->head.next; current != &ptr->head; current=current->next)
    {
        if(cmp(key,current->data)==0)//假設數據沒重複,找一個找到返回
            break;
    }
    return current;
}

void *linked_find(linked *p,const void *key,linked_cmp *cmp)
{
    node *node;
    struct linked_head_st *ptr = p;
    node = find_(ptr,key,cmp);
    if(node == &ptr->head)
        return NULL;
    return node->data;
}

int linked_delete(linked *p,const void *key,linked_cmp *cmp)
{
    node *node;
    struct linked_head_st *ptr = p;
    node = find_(ptr,key,cmp);
    if (node == NULL)
        return -1;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    free(node);
    return 0;
}

int linked_fetch(linked *p,const void *key,linked_cmp *cmp,void *data)
{
    node *node;
    struct linked_head_st *ptr = p;
    node = find_(ptr,key,cmp);
    if (node == NULL)
        return -1;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    if(data != NULL)
        memcpy(data,node->data,ptr->size);
    free(node);
    return 0;
}

void linked_travel(linked *p, linked_op *op)
{
    node *current;
    struct linked_head_st *ptr = p;
    for (current = ptr->head.next; current != &ptr->head; current = current->next)
        op(current->data);
}

void linked_destroy(linked *p)
{
    node *current, *next;
    struct linked_head_st *ptr = p;

    for (current = ptr->head.next; current != &ptr->head; current = next)
    {
        next = current->next;
        free(current);
    }
    free(ptr);
}