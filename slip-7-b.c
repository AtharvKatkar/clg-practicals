// Write a program that checks whether a string of characters is palindrome
// or not. The function should use a stack library (cststack.h) of stack of
// characters using a static implementation of the stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10

char inp[MAX_SIZE];
int pt = -1;

void push(char d)
{
    if (pt >= MAX_SIZE)
    {
        printf("Input exceeds 10 chars \n");
        return;
    }

    pt++;
    inp[pt] = d;
}

char pop()
{
    if (pt < 0)
    {
        printf("Stack underflow \n");
        return '\0';
    }

    char d = inp[pt];
    pt--;
    return d;
}

int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (isalnum(str[i]))
        {
            push(tolower(str[i]));
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (isalnum(str[i]))
        {
            if (tolower(str[i]) != pop())
            {
                return 0;
            }
        }
    }

    return 1;
}

void main()
{
    char str[MAX_SIZE];
    printf("Enter string \n");
    scanf("%s", str);

    if (isPalindrome(str))
    {
        printf("String is palindrome  \n");
    }
    else
    {
        printf("String is not palindrome  \n");
    }
}