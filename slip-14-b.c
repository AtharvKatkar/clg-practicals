#include <stdio.h>
#include "slip-14-b.h"

int main()
{
    Queue q;
    initQueue(&q);

    // Add elements to the queue
    addFront(&q, 10);
    addFront(&q, 5);

    // Print the elements in the queue
    printf("Rear: %d\n", getRear(&q));

    // Delete elements from the queue
    deleteRear(&q);

    // Print the elements in the queue
    printf("Rear: %d\n", getRear(&q));

    return 0;
}
