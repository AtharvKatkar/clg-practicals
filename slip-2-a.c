#include <stdio.h>
#include "singlell.h"

void printMenu()
{
    printf("\nOperations available \n\n");
    printf("1) Create New Node \n");
    printf("2) Display Node \n");
    printf("3) Exit \n");
}

void main()
{
    int ch;
    Node *a = createNode(0);
    while (1)
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int data;
            printf("Enter data to be added to the node:\n");
            scanf("%d", &data);
            Node *newNode = createNode(data);
            Node *last = getLastNode(a);
            connectNode(last, newNode);
            break;

        case 2:
            printLL(a);
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
}