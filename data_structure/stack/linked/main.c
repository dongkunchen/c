//鏈式存儲模擬stack
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define NAMESIZE 32

typedef struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int english;
} score;

static void print_s(void *record)
{
    score *r = record;
    printf("%d %s %d %d\n",r->id,r->name,r->math,r->english);
}

int main()
{
    stack *st;
    score tmp;
    int i,ret;

    st = stack_create(sizeof(score));
    if (st == NULL)
        exit(1);
    printf("入棧:\n");    
    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.english = rand() % 100;
        if (stack_push(st, &tmp))
            exit(1);
        print_s(&tmp);
    }

    printf("出棧:\n");    
    while (1)
    {
        ret = stack_pop(st, &tmp);
        if (ret == -1)
            break;
        print_s(&tmp);
    }

    stack_destroy(st);

    return 0;
}