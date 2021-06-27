#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

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
    int i, ret;
    queue *qu;
    score tmp;

    qu = queue_create(sizeof(score));
    if (qu == NULL)
        exit(1);

    //入隊
    printf("enqueue:\n");
    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.english = rand() % 100;
        if (queue_enqueue(qu, &tmp) != 0)
            break;
        print_s(&tmp);
    }

    //出隊
    printf("dequeue:\n");
    while (1)
    {
        ret = queue_dequeue(qu, &tmp);
        if (ret == -1)
            break;
        print_s(&tmp);
    }

    queue_destroy(qu);

    return 0;
}