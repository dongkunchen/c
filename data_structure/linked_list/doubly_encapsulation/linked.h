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

typedef struct linked_head
{
    int size;
    struct linked_node_st head;
    int (*insert)(struct linked_head *, const void *, int);
    void *(*find)(struct linked_head *, const void *, linked_cmp *);
    int (*delete)(struct linked_head *, const void *, linked_cmp *);
    int (*fetch)(struct linked_head *, const void *, linked_cmp *, void *);
    void (*travel)(struct linked_head *, linked_op *);
} linked;

linked *linked_create(int);

void linked_destroy(linked *);

#endif