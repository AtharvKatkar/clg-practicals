#include <stdio.h>

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int index = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > index)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = index;
    }
}

void main()
{
    int len, num;
    printf("Enter lenght \n");
    scanf("%d", &len);

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter element: ");
        scanf("%d", &num);
        arr[i] = num;
    }

    printf("\nInput Array\n");
    printArr(arr, len);
    sort(arr, len);
    printf("\nSorted array\n");
    printArr(arr, len);
}