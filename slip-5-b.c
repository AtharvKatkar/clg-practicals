#include <stdio.h>
#include "priQueue.h"

void main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10, 1);
    enqueue(&q, 20, 2);
    enqueue(&q, 30, 3);
    enqueue(&q, 40, 4);

    printf("Original queue\n");
    printQueue(&q);

    dequeue(&q);
    dequeue(&q);

    printf("Original queue\n");
    printQueue(&q);
}