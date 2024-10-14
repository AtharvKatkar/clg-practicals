// NOTE: does not work yet

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(char *a[100], char *b[100])
{
    char temp[100] = *a;
    *a = *b;
    *b = temp;
}

void sort(char arr[100][100], int len)
{
    int i, j;
    bool swapped;
    for (i = 0; i < len - 1; i++)
    {
        swapped = false;
        for (j = 0; j < len; j++)
        {
            int result = strcmp(arr[j], arr[j + 1]);
            if (result < 0)
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

void printArr(char arr[100][100], int len)
{
    for (int i = len; i >= 0; i--)
    {
        printf("%s \n", arr[i]);
    }
}

void main()
{
    char nameArray[100][100];
    FILE *fp;
    fp = fopen("mp-sp-30.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s", nameArray[i]);
        i = i + 1;
    }

    printf("Orginal Array \n");
    printArr(nameArray, i);
    sort(nameArray, i);
    printf("Sorted Array \n");
    printArr(nameArray, i);
}