/*
    Binary Search

    Problem: First and last position in sorted array
    leetcode:34
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int RightMost(vector<int>& nums, int target)
    {
        int n = nums.size() - 1;

        int l = 0;
        int r = n;
        int rightmost = -1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target)
            {
                rightmost = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }

        }
        return rightmost;
    }

    int LeftMost(vector<int>& nums, int target)
    {
        int n = nums.size() - 1;

        int l = 0;
        int r = n;
        int leftmost = -1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target)
            {
                leftmost = mid;
                r = mid - 1;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

        }

        return leftmost;
    }
     vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int right_most = RightMost(nums,target);
        int left_most = LeftMost(nums,target);


        return{left_most,right_most};
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

    vector<int> iRet = sobj.searchRange(nums, target);

    cout<<"Rightmost = "<<iRet[0]<<" "<<"Leftmost = "<<iRet[1];

    return 0;
}