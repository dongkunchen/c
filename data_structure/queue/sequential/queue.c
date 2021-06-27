//circular queue
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

queue *qu_create()
{
    queue *sq;
    sq = malloc(sizeof(*sq));
    if (sq == NULL)
        return NULL;
    sq->head = 0;
    sq->tail = 0;
    return sq;
}

int qu_isempty(queue *sq)
{
    return (sq->tail == sq->head);
}

int qu_enqueue(queue *sq, datatype *data)
{
    if ((sq->tail + 1) % MAXSIZE == sq->head)
        return -1;
    sq->tail = (sq->tail + 1) % MAXSIZE;
    sq->data[sq->tail] = *data;
    return 0;
}

int qu_dequeue(queue *sq, datatype *data)
{
    if(qu_isempty(sq))
        return -1;
    sq->head = (sq->head+1)%MAXSIZE;
    *data = sq->data[sq->head];
}

void qu_travel(queue *sq)
{
    int i;
    if (sq->head == sq->tail)
        return;
    i = (sq->head + 1) % MAXSIZE;
    while (i != sq->tail)
    {
        printf("enqueue: %d\n", sq->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("enqueue: %d\n",sq->data[i]);
}

void qu_clear(queue *sq)
{
    sq->head = sq->tail;
}

void qu_destroy(queue *sq)
{
    free(sq);
}