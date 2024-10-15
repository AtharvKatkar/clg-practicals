#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[5] = {2, 9, 3, 5, 7};
    printf("Orginal array \n");
    printArray(arr, 5);
    insertionSort(arr, 5);
    printf("Sorted array \n");
    printArray(arr, 5);
}