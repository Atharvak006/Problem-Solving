/*
    Binary Search

    Problem: Leetcode Search Insert Position.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
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
};

int main()
{
    int Size;

    cout << "Enter the size of the array: ";
    cin >> Size;

    vector<int> nums(Size);

    cout << "Enter the elements of the sorted array:" << endl;
    for (int i = 0; i < Size; i++)
    {
        cin >> nums[i];
    }

    int target;

    cout << "Enter the target: ";
    cin >> target;

    Solution sobj;

    int iRet = sobj.searchInsert(nums, target);

    cout << "Insert Position = " << iRet << endl;

    return 0;
}