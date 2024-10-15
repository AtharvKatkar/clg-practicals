#include <stdio.h>
#define MAX_SIZE 10

typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
} Stack;

void *init(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int data)
{
    if (s->top >= MAX_SIZE)
    {
        printf("overflow \n");
        return;
    }

    s->top++;
    s->data[s->top] = data;
}

int pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("underflow \n");
        return -1;
    }
    return s->data[s->top--];
}

int isIdentical(Stack *s1, Stack *s2)
{
    if (s1->top != s2->top)
    {
        printf("uneven size \n");
        return 0;
    }
    for (int i = 0; i <= s1->top && i <= s2->top; i++)
    {
        // printf("comparing %d %d", s1->data[i], s2->data[i]);
        if (s1->data[i] != s2->data[i])
        {
            printf("%d != %d \n", s1->data[i], s2->data[i]);
            return 0;
        }
    }

    return 1;
}

void main()
{
    Stack stack1, stack2;
    init(&stack1);
    init(&stack2);

    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);
    push(&stack2, 1);
    push(&stack2, 2);
    push(&stack2, 4);

    if (isIdentical(&stack1, &stack2))
    {
        printf("stacks are identical \n");
    }
    else
    {
        printf("stacks are not identical \n");
    }
}