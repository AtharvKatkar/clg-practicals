#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void connectNode(Node *head, Node *next)
{
    head->next = next;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
}

Node *getLastNode(Node *head)
{
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    return last;
}