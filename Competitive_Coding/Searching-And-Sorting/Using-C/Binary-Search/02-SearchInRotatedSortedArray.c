#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize)
{
    int l = 0;
    int r = numsSize - 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else
        {
            // mid may be the minimum element
            r = mid;
        }
    }

    return nums[l];
}

int main()
{
    int numsSize;

    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int *nums = (int *)malloc(numsSize * sizeof(int));

    if (nums == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the rotated sorted array:\n");
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }

    int min = findMin(nums, numsSize);

    printf("Minimum element in the rotated sorted array is: %d\n", min);

    free(nums);

    return 0;
}