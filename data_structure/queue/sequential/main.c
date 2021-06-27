//circular queue
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
    int i, ret;
    queue *sq;
    datatype data[] = {10, 30, 60, 20};

    sq = qu_create();
    if (sq == NULL)
        exit(1);
    for (i = 0; i < sizeof(data) / sizeof(*data); i++)
        qu_enqueue(sq, &data[i]); //入隊

    qu_travel(sq);

    // datatype tmp = 70;
    // ret = qu_enqueue(sq,&tmp);
    // if(ret == -1)
    //     printf("queue is full!\n");
    // else
    //     qu_travel(sq);

    //出隊
    printf("=================\n");
    datatype tmp;
    while (sq->head != sq->tail)
    {
        qu_dequeue(sq, &tmp);
        printf("dequeue: %d\n", tmp);
    }

    qu_destroy(sq);

    return 0;
}