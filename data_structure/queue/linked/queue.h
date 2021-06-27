#ifndef QUEUE_H__
#define QUEUE_H__

#include "linked.h"

typedef linked queue;

queue *queue_create(int);

int queue_enqueue(queue *, const void *);

int queue_dequeue(queue *, void *);

void queue_destroy(queue *);

#endif