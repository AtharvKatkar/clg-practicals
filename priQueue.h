#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int pri[MAX_SIZE];
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

void enqueue(Queue *q, int data, int priority)
{
    if (isFull(q) == 1)
    {
        printf("Queue if full\n");
        return;
    }
    q->data[q->rear] = data;
    q->pri[q->rear] = priority;
    q->rear++;
}

void dequeue(Queue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

void printQueue(Queue *q)
{
    for (int i = q->front + 1; i < q->rear; i++)
    {
        printf("data: %d pri: %d \n", q->data[i], q->pri[i]);
    }
}

void rmByPri(Queue *q, int pri)
{
    // TODO: implement this function
}