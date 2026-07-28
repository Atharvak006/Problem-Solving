/*
    Binary Search

    Problem: First and Last Position of Element in Sorted Array
    LeetCode: 34

    Time Complexity : O(log n)
    Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

// Find Leftmost Occurrence
int LeftMost(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    int leftmost = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            leftmost = mid;
            r = mid - 1;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return leftmost;
}

// Find Rightmost Occurrence
int RightMost(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    int rightmost = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            rightmost = mid;
            l = mid + 1;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return rightmost;
}

// Main Search Function
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;

    int* ans = (int*)malloc(2 * sizeof(int));

    ans[0] = LeftMost(nums, numsSize, target);
    ans[1] = RightMost(nums, numsSize, target);

    return ans;
}

int main()
{
    int numsSize;

    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));

    if (nums == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }

    int target;

    printf("Enter the target element: ");
    scanf("%d", &target);

    int returnSize;

    int* ans = searchRange(nums, numsSize, target, &returnSize);

    if (ans[0] != -1)
    {
        printf("First Position : %d\n", ans[0]);
        printf("Last Position  : %d\n", ans[1]);
    }
    else
    {
        printf("Target not found in the array.\n");
    }

    free(ans);
    free(nums);

    return 0;
}