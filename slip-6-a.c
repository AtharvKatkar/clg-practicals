#include <stdio.h>
#include "dyqueue.h"

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued element: %d\n", dequeue(&q)); // Output: Dequeued element: 10
    printf("Peeked element: %d\n", peek(&q));      // Output: Peeked element: 20
    printf("Queue is empty? %d\n", isEmpty(&q));   // Output: Queue is empty? 0 (false)

    return 0;
}
