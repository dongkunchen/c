//順序存儲模擬stack
#ifndef STACK_H__
#define STACK_H__

#define MAXSIZE     9

typedef int datatype;

typedef struct node_st
{
    datatype data[MAXSIZE];
    int top;
}stack;

stack *st_create(void);

int st_isempty(stack *);

int st_push(stack *,datatype *);

int st_pop(stack *,datatype *);

int st_top(stack *,datatype *);

void st_travel(stack *);

void st_destroy(stack *);

#endif