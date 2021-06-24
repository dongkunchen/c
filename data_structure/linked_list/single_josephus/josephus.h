#ifndef JOSEPHUS_H__
#define JOSEPHUS_H__

#define JOSE_NUM    8
#define JOSE_KILL   3

typedef struct node_st
{
    int data;
    struct node_st *next;
}node;

node *jose_insert(int );

void jose_show(node *);

void jose_kill(node **, int);


#endif