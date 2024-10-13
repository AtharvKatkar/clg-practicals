#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to evaluate the postfix expression
int evaluatePostfix(char *expression)
{
    int stack[MAX_SIZE];
    int top = -1;
    int i, operand1, operand2, result;
    for (i = 0; expression[i]; i++)
    {
        if (isdigit(expression[i]))
        {
            stack[++top] = expression[i] - '0';
        }
        else if (expression[i] == ' ')
        {
            continue;
        }
        else
        {
            if (top < 1)
            {
                printf("Invalid expression\n");
                return -1;
            }
            operand2 = stack[top--];
            operand1 = stack[top--];
            switch (expression[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Division by zero\n");
                    return -1;
                }
                result = operand1 / operand2;
                break;
            default:
                printf("Invalid operator\n");
                return -1;
            }
            stack[++top] = result;
        }
    }
    if (top != 0)
    {
        printf("Invalid expression\n");
        return -1;
    }
    return stack[top];
}

int main()
{
    char expression[100];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;
    printf("Result: %d\n", evaluatePostfix(expression));
    return 0;
}
