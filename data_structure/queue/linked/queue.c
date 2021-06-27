#include "queue.h"


queue *queue_create(int initsize)
{
    return linked_create(initsize);
}

int queue_enqueue(queue *ptr,const void *data)
{
    return linked_insert(ptr,data,LINKED_BACKWARD);
}

static int always_match(const void *p1,const void *p2)
{
    return 0;
}

int queue_dequeue(queue *ptr,void *data)
{
    return linked_fetch(ptr,(void *)0,always_match,data);
}

void queue_destroy(queue *ptr)
{
    linked_destroy(ptr);
}
