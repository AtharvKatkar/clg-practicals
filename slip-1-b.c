#include <stdio.h>
#include <stdbool.h>

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
    int arr[5] = {6, 9, 0, 3, 5};
    printf("original array: \n");
    printArray(arr, 5);
    bubbleSort(arr, 5);
    printf("sorted array: \n");
    printArray(arr, 5);
}