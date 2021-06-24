#ifndef NOHEAD_H__
#define NOHEAD_H__

#define NAMESIZE 32

typedef struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int english;
} datatype;

typedef struct node_st
{
    datatype data;
    struct node_st *next;
} node;

int list_insert(node **, datatype *);//二級傳參
// node * list_insert(node *, datatype *);//一級傳參

void list_show(node *);

int list_delete(node **);

// int list_find(node *, int id);
datatype * list_find(node *, int);

void list_destroy(node *);

#endif