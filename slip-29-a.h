#include <stdio.h>

int *initStack(int len)
{
    int stack[len];
    return stack;
}

int push(int stack[], int data, int *pointer)
{
    *pointer++;
    stack[*pointer] = data;
    return stack[*pointer];
}

int pop(int stack[], int *pointer)
{
    int data = stack[*pointer];
    *pointer--;
    return data;
}

void printStack(int stack[], int *pointer)
{
    for (int i = *pointer; i >= 0; i++)
    {
        printf("%d ", stack[i]);
    }
}