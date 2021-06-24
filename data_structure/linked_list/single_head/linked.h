#ifndef LINKED_H__
#define LINKED_H__

typedef int datatype;

typedef struct node_st
{
    datatype data;
    struct node_st *next;    
}linked;

linked *linked_create();

int linked_insert_at(linked *,int i,datatype *);

int linked_insert_order(linked *,datatype *);

int linked_delete_at(linked *,int i,datatype *);

int linked_delete(linked *,int num);

int linked_isempty(linked *);

void linked_display(linked *);

void linked_destroy(linked *);

#endif