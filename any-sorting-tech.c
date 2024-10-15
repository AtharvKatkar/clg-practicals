#include <stdio.h>
#include <stdlib.h>

// Common functions
void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Functions for insertion sort
void insertionSort(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
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

// functions for quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Selection sort
void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int key_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[key_index])
            {
                key_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[key_index];
        arr[key_index] = temp;
    }
}

// count sort
void countSort(int inputArray[], int N)
{
    int M = 0;
    for (int i = 0; i < N; i++)
        if (inputArray[i] > M)
            M = inputArray[i];
    int *countArray = (int *)calloc(M + 1, sizeof(int));
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
    int *outputArray = (int *)malloc(N * sizeof(int));
    for (int i = N - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }
    for (int i = 0; i < N; i++)
        inputArray[i] = outputArray[i];
    free(countArray);
    free(outputArray);
}

// Common main function for sorting
void main()
{
    int len;
    printf("Enter length of array: ");
    scanf("%d", &len);
    int arr[len];

    for (int i = 0; i < len; i++)
    {
        printf("Enter element for position %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, len);
    // insertionSort(arr, len);
    // quickSort(arr, 0, len - 1);
    // selectionSort(arr, len);
    countSort(arr, len);
    printf("Sorted array: \n");
    printArray(arr, len);
}