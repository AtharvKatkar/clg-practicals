#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data, Node *next, Node *prev)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}

void displayLL(Node *head)
{
    Node *temp = head;
    printf("Printing linked list");
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}