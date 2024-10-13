#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int arr[], int len)
{
    int i, j, min_index; // 5 4
    for (i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (j = 0; j < len; j++)
        {
            // Find minimum array
            if (arr[j] > arr[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&arr[min_index], &arr[i]);
        }
    }
}

void main()
{
    int arr[5] = {64, 12, 11, 22, 25};
    printf("Original array \n");
    printArray(arr, 5);
    sort(arr, 5);
    printf("Sorted array \n");
    printArray(arr, 5);
}