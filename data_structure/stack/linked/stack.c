//鏈式存儲模擬stack
#include <stdio.h>

#include "stack.h"


linked *stack_create(int initsize)
{
    return linked_create(initsize);
}

int stack_push(stack *ptr, const void *data)
{
    return linked_insert(ptr,data,LINKED_FORWARD);
}

static int always_match(const void *p1,const void *p2)
{
    return 0;
}

int stack_pop(stack *ptr, void *data)
{
    return linked_fetch(ptr,(void *)0,always_match,data);
}

void stack_destroy(stack *ptr)
{
    linked_destroy(ptr);
}

