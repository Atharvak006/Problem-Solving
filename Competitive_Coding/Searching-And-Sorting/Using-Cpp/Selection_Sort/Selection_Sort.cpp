#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        void Selection(vector<int>& arr)
        {
            int n = arr.size();

            for(int i = 0; i < n-1; i++)
            {
                int min = i;
                for(int j = i+1; j < n; j++)
                {
                    if(arr[j] < arr[min])
                    {
                        min = j;
                    }
                }
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
};
int main(void)
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Before sorting: ";

    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<"\nAfter sorting: ";
    
    Solution sobj;
    sobj.Selection(arr);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}