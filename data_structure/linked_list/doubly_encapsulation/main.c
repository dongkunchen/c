#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked.h"

#define NAMESIZE 32

typedef struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int english;
} score;

static void print_score(const void *record)
{
    const score *ptr = record;
    printf("%d %s %d %d\n", ptr->id, ptr->name, ptr->math, ptr->english);
}

static int id_cmp(const void *key, const void *record)
{
    const int *k = key;
    const score *r = record;
    return (*k-r->id);
}

static int name_cmp(const void *key, const void *record)
{
    const char *k = key;
    const score *r = record;
    return strcmp(k,r->name);
}

int main()
{
    linked *handler;
    score tmp;
    int i, ret;

    handler = linked_create(sizeof(score));

    if (handler == NULL)
        exit(1);

    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.english = rand() % 100;
        ret = handler->insert(handler, &tmp, LINKED_BACKWARD);
        if (ret)
            exit(1);
    }

    handler->travel(handler, print_score);

    linked_destroy(handler);

    exit(0);
}