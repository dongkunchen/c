#ifndef LINKED_H__
#define LINKED_H__

#define LINKED_FORWARD 1
#define LINKED_BACKWARD 2

typedef void linked_op(const void *);
typedef int linked_cmp(const void *, const void *);

typedef struct linked_node_st
{
    struct linked_node_st *pre;
    struct linked_node_st *next;
    char data[1];//修改為可變長結構體
    
} node;

typedef struct
{
    int size;
    struct linked_node_st head;
} linked;

linked *linked_create(int);

int linked_insert(linked *, const void *, int);

void *linked_find(linked *, const void *, linked_cmp *);

int linked_delete(linked *, const void *, linked_cmp *);

int linked_fetch(linked *, const void *, linked_cmp *, void *);

void linked_travel(linked *, linked_op *);

void linked_destroy(linked *);

#endif