#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("Error: Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int pre(char c)
{
    if (c == "+" || c == "-")
        return 1;
    else if (c == "*" || c == "/")
        return 2;
    else if (c == "^")
        return 3;
    else
        return 0;
}

int isOperation(char c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}

void infixPostfix(char *infix, char *postfix)
{
    int i, j = 0;
    char c;

    for (i = 0; infix[i]; i++)
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == "(")
            push(infix[i]);
        else if (infix[i] == ")")
            while ((c == pop()) != "(")
                postfix[j++] = c;
        else
        {
            while (top != -1 && pre(stack[top]) >= pre(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
}