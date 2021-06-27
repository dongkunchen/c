//順序存儲模擬stack
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack *st_create(void)
{
    stack *st;
    st = malloc(sizeof(*st));
    if (st == NULL)
        return NULL;
    st->top = -1;
    return st;
}

int st_isempty(stack *st)
{
    return (st->top == -1);
}

int st_push(stack *st, datatype *data)
{
    if (st->top == (MAXSIZE - 1))
        return -1;
    st->data[++st->top] = *data;
    return 0;
}

int st_pop(stack *st, datatype *data)
{
    if (st_isempty(st))
        return -1;
    *data = st->data[st->top--];
    return 0;
}

int st_top(stack *st, datatype *data)
{
    if (st_isempty(st))
        return -1;
    *data = st->data[st->top];
    return 0;
}

void st_travel(stack *st)
{
    int i;
    if (st_isempty(st))
        return;
    for (i = 0; i <= st->top; i++)
        printf("%d ", st->data[i]);
    printf("\n");
}

void st_destroy(stack *st)
{
    free(st);
}