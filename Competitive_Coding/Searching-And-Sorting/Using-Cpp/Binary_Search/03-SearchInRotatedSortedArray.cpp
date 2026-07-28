/*
    Binary Search

    Problem: Search in Rotated Sorted Array

    Approach:
    1. Find the pivot (smallest element) using Binary Search.
    2. Perform Binary Search on the left side of the pivot.
    3. If not found, perform Binary Search on the right side of the pivot.

    Time Complexity : O(log n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to find pivot (index of minimum element)
    int pivotIndex(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return r;
    }

    // Binary Search on Left Side of Pivot
    int Binary_search_left_side_of_pivot(int l, int r, vector<int>& nums, int target)
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
    int Binary_search_right_side_of_pivot(int l, int r, vector<int>& nums, int target)
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

    int search(vector<int>& nums, int target)
    {
        int pivot_index = pivotIndex(nums);

        // Search in left half
        int idx1 = Binary_search_left_side_of_pivot(0, pivot_index - 1, nums, target);

        if (idx1 != -1)
        {
            return idx1;
        }

        // Search in right half
        int idx2 = Binary_search_right_side_of_pivot(pivot_index, nums.size() - 1, nums, target);

        if (idx2 != -1)
        {
            return idx2;
        }

        return -1;
    }
};

int main()
{
    int Size;

    cout << "Enter the size of the array: ";
    cin >> Size;

    vector<int> nums(Size);

    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < Size; i++)
    {
        cin >> nums[i];
    }

    int target;

    cout << "Enter the target element: ";
    cin >> target;

    Solution sobj;

    int iRet = sobj.search(nums, target);

    if (iRet != -1)
    {
        cout << "Target found at index : " << iRet << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}