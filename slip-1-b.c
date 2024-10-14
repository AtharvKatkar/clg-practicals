#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
}

int *LinkedListToArray(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    int *arr = (int *)malloc(len * sizeof(int));

    temp = head;
    int i = 0;
    while (temp)
    {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }

    return arr;
}

Node *ArrayToLinkedList(int arr[], int len)
{
    if (len == 0)
    {
        return NULL; // Return NULL if the array is empty
    }

    Node *sortedLL = createNode(arr[0]);
    Node *last_node = sortedLL;

    for (int i = 1; i < len; i++)
    {
        Node *nn = createNode(arr[i]);
        connectNode(last_node, nn);
        last_node = nn;
    }

    return sortedLL;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int len)
{
    int i, j;
    bool swaped;
    for (i = 0; i < len - 1; i++)
    {
        swaped = false;
        for (j = 0; j < len; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swaped = true;
            }
        }

        if (swaped == false)
        {
            break;
        }
    }
}

void main()
{
    // Normal bubble sort code
    // int arr[5] = {6, 9, 0, 3, 5};
    // printf("original array: \n");
    // printArray(arr, 5);
    // bubbleSort(arr, 5);
    // printf("sorted array: \n");
    // printArray(arr, 5);

    Node *a = createNode(10);
    Node *b = createNode(2);
    Node *c = createNode(8);
    Node *d = createNode(5);

    connectNode(a, b);
    connectNode(b, c);
    connectNode(c, d);

    printf("Original Linked list \n");
    printLinkedList(a);
    printf("\n");

    int *arr = LinkedListToArray(a);
    // Debugging statements not required for exam
    // NOT NEEDED printArray(arr, 4);
    printf("\n");

    // Sort the array to sorted array
    bubbleSort(arr, 4);
    // NOT NEEDED printArray(arr, 4);

    Node *sortedLinkedLL = ArrayToLinkedList(arr, 4);
    printf("Sorted Linked list \n");
    printLinkedList(sortedLinkedLL);
    printf("\n");
}