/*
    Binary Search

    Problem: Search in Rotated Sorted Array

    Approach:
    1. Find the pivot (index of the minimum element) using Binary Search.
    2. Perform Binary Search on the left side of the pivot.
    3. If not found, perform Binary Search on the right side of the pivot.

    Time Complexity : O(log n)
    Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the pivot (index of minimum element)
int pivotIndex(int* nums, int numsSize)
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

    return r;
}

// Binary Search on Left Side of Pivot
int BinarySearchLeft(int l, int r, int* nums, int target)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            return mid;
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

    return -1;
}

// Binary Search on Right Side of Pivot
int BinarySearchRight(int l, int r, int* nums, int target)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            return mid;
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

    return -1;
}

// Main Search Function
int search(int* nums, int numsSize, int target)
{
    int pivot = pivotIndex(nums, numsSize);

    // Search in left half
    int idx1 = BinarySearchLeft(0, pivot - 1, nums, target);

    if (idx1 != -1)
    {
        return idx1;
    }

    // Search in right half
    int idx2 = BinarySearchRight(pivot, numsSize - 1, nums, target);

    if (idx2 != -1)
    {
        return idx2;
    }

    return -1;
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

    printf("Enter the elements of the rotated sorted array:\n");
    for (int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }

    int target;

    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = search(nums, numsSize, target);

    if (index != -1)
    {
        printf("Target found at index: %d\n", index);
    }
    else
    {
        printf("Target not found in the array.\n");
    }

    free(nums);

    return 0;
}