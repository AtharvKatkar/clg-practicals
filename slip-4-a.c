#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[5], int n)
{
    int i, j, swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

void printArr(int arr[5], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    int arr[5] = {23, 93, 6, 24, 774};
    printf("Original array \n");
    printArr(arr, 5);
    sort(arr, 5);
    printf("Sorted array \n");
    printArr(arr, 5);
}