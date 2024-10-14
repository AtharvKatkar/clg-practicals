#include <stdio.h>

#define MAX_SIZE 10

typedef struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue q)
{
    return ((q.rear + 1) % MAX_SIZE) == q.front;
}

int isEmpty(Queue q)
{
    return q.front == q.front;
}

void addFront(Queue *q, int data)
{
    // if (isFull(*q))
    // {
    //     printf("Queue overflow \n");
    //     return;
    // }
    q->front = ((q->front - 1 + MAX_SIZE) % MAX_SIZE);
    q->data[q->front] = data;
}

int getRear(Queue *q)
{
    return q->data[q->rear];
}

void deleteRear(Queue *q)
{
    if (isEmpty(*q))
    {
        printf("Empty queue");
        return;
    }
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
}