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
}

void connectNode(Node *head, Node *next)
{
    head->next = next;
}

Node *getLastNode(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

Node *copyLL(Node *head_ll1, Node *head_ll2)
{
    Node *temp = head_ll1;
    Node *last_node_ll1 = getLastNode(temp);
    last_node_ll1->next = head_ll2;
    return temp;
}

void main()
{
    // Create linked list 1: 10 -> 20
    Node *a = createNode(10);
    Node *b = createNode(20);
    connectNode(a, b);
    printf("Linked list 1: ");
    printLL(a);
    printf("\n");

    // Create linked list 1: 30 -> 40
    Node *c = createNode(30);
    Node *d = createNode(40);
    connectNode(c, d);
    printf("Linked list 2: ");
    printLL(c);
    printf("\n");

    Node *copy = copyLL(a, c);
    printf("Copied linked list: ");
    printLL(copy);
    printf("/n");
}