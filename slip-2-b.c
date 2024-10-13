#include <stdio.h>

int pointer = -1;

void push(int data, int stack[], int len)
{
    if (pointer >= len)
    {
        printf("Stackoverflow!! \n");
        return;
    }
    pointer++;             // 0
    stack[pointer] = data; // stack[0] = 1
    printf("%d added to stack \n", data);
}

void pop(int stack[])
{
    if (pointer >= 0)
    {
        pointer--;
    }
    else
    {
        printf("Stackunderflow!! \n");
    }
}

void printStack(int stack[])
{
    for (int i = pointer; i >= 0; i--)
    {
        printf("| %d |\n", stack[i]);
    }
}

void copyStk(int stk1[], int stk2[], int len)
{
    for (int i = len; i >= 0; i--)
    {
        stk2[i] = stk1[i];
    }
    printf("\nContent copied\n\n");
    printf("\nStack 1\n\n");
    printStack(stk1);
    printf("\nStack 2\n\n");
    printStack(stk2);
}

void printMenu()
{
    printf("\nOperations on stack\n");
    printf("1) Push element \n");
    printf("2) Pop element \n");
    printf("3) Display stack\n");
    printf("4) Copy stack\n");
}

void main()
{
    int stk1[5], stk2[5], ch;

    while (1)
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int data;
            printf("Enter data:");
            scanf("%d", &data);
            push(data, stk1, 5);
            break;

        case 2:
            pop(stk1);
            break;

        case 3:
            printf("\nSelect stack\n\n1) Stack 1\n2) Stack 2\n");
            int sel;
            scanf("%d", &sel);
            if (sel == 1)
            {
                printStack(stk1);
            }
            else
            {
                printStack(stk2);
            }
            break;

        case 4:
            copyStk(stk1, stk2, pointer);
            break;

        default:
            break;
        }
    }
}