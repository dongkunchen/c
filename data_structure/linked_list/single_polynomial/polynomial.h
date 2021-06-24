#ifndef POLYNOMIAL_H__
#define POLYNOMIAL_H__

typedef struct node_st
{
    int coefficient;//係數
    int exponent;//指數
    struct node_st *next;
}node;

node *poly_create();

node *poly_insert(node *,int (*arr)[],int );

void poly_show();

void poly_union(node *p1,node *p2);

#endif