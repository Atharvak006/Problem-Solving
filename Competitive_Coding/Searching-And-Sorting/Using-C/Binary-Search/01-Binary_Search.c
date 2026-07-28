/*
    Binary Search;

    Problem: Leetcode Search Insert Position.
*/

#include <stdio.h>
#include <stdlib.h>

int Search_Insert_Position(int *Arr, int Size, int target)
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (Arr[mid] == target)
        {
            return mid;
        }
        else if (Arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main(void)
{
    int Size;

    printf("Enter the size of the array: ");
    scanf("%d", &Size);

    int *Arr = (int *)malloc(Size * sizeof(int));

    printf("Enter the elements of array (sorted):\n");
    for (int i = 0; i < Size; i++)
    {
        scanf("%d", &Arr[i]);
    }

    int target;

    printf("Enter the target: ");
    scanf("%d", &target);

    int iRet = Search_Insert_Position(Arr, Size, target);

    printf("Insert Position = %d\n", iRet);


    // free the array.
    free(Arr);

    return 0;
}