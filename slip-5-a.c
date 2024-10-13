#include <stdio.h>

void main()
{
    int len, num, key, flag = 0, pos;
    printf("Enter length of the array: ");
    scanf("%d", &len);
    int arr[len];

    printf("\nEnter elements in the array \n");
    for (int i = 0; i < len; i++)
    {
        printf("Number %d ", i);
        scanf("%d", &num);
        printf("\n");
        arr[i] = num;
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &key);
    printf("\n");

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == key)
        {
            pos = i;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\n%d found at position %d\n", key, pos);
    }
    else
    {
        printf("\n%d not found in array\n", key);
    }
}