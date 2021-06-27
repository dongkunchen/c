//鏈式存儲模擬stack
#ifndef STACK_H__
#define STACK_H__

#include "linked.h"

typedef linked stack;

stack *stack_create(int);

int stack_push(stack *, const void *);

int stack_pop(stack *, void *);

void stack_destroy(stack *);

#endif