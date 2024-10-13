#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = 0;
}

int isEmpty(Queue *q)
{
    if (q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Queue *q)
{
    if (q->rear == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *q, int data)
{
    if (isFull(q) == 1)
    {
        printf("Queue is full! \n");
        return;
    }

    q->data[q->rear] = data;
    q->rear++;
}

void dequeue(Queue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Queue is empty! \n");
        return;
    }

    q->front++;
}

void printQueue(Queue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Queue is empty! \n");
        return;
    }

    printf("Queue\n");
    for (int i = q->front + 1; i < q->rear; i++)
    {
        printf("%d ->", q->data[i]);
    }
}

void revQueue(Queue *q)
{
    Queue revQ;
    initQueue(&revQ);

    for (int i = q->rear - 1; i > q->front; i--)
    {
        enqueue(&revQ, q->data[i]);
    }

    printf("Reversed queue \n");
    printQueue(&revQ);
}

void main()
{
    Queue q;
    initQueue(&q);
    int ch;

    while (1)
    {
        printf("\nOperations available on Queue.\n1) Enqueue\n2) Dequeue\n3) Print Queue\n4) Rev queue\n\nEnter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            int data;
            printf("Enter data to be enqueued: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            printQueue(&q);
            break;
        case 4:
            revQueue(&q);
            break;
        default:
            printf("\nInvalud selection\n");
            break;
        }
    }
}