/*
    Here we use two pointers approach.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        void moveZeroes(vector<int>& nums)
        {
            int n = nums.size();

            int left = 0;

            for(int right = 0; right < nums.size(); right++)
            {
                if(nums[right] != 0)
                {
                    // swap
                    int temp = nums[right];
                    nums[right] = nums[left];
                    nums[left] = temp;
                    left++;
                }
            }
        }
};
int main(void)
{   
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    vector<int> arr(size);

    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    cout<<"Before moving: ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    cout<<"After moving: ";
    
    Solution sobj;
    sobj.moveZeroes(arr);

    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}