/*
    Binary Search

    Problem: Minimum In rotated sorted.
    here also we use binary search with some changes.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size()-1;

        while(l < r) // Unlike Normal Binary search where we do l <= r ..here we have to do l < r
        {
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
                // Here we have to do r = mid because here mid element is less than r and chances are 
                // mid element may be our answer hence we do r = mid and not r = mid - 1
            }
        }

        return nums[r];
    }
    
};

int main()
{
    int Size;

    cout << "Enter the size of the array: ";
    cin >> Size;

    vector<int> nums(Size);

    cout << "Enter the elements of the sorted array:";
    for (int i = 0; i < Size; i++)
    {
        cin >> nums[i];
    }


    Solution sobj;

    int iRet = sobj.findMin(nums);

    cout << "Minimum element in rotated sorted array is :  " << iRet << endl;

    return 0;
}