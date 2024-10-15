#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

void init(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, int data)
{
    QueueNode *nn = (QueueNode *)malloc(sizeof(QueueNode));
    nn->data = data;
    nn->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = nn;
    }
    else
    {
        q->rear->next = nn;
        q->rear = nn;
    }
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return -1;
    }
    int value = q->front->data;
    QueueNode *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear == NULL;
    }

    free(temp);
    return value;
}

int peek(Queue *q)
{
    if (q->front == NULL)
    {
        return -1;
    }

    return q->front->data;
}

int isEmpty(Queue *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
