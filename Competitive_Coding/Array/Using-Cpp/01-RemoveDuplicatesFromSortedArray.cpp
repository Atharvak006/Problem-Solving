#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int RemoveDuplicates(vector<int>& arr)
    {
        int n = arr.size();

        if (n == 0)
        {
            return 0;
        }

        int j = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[j])
            {
                j++;
                arr[j] = arr[i];
            }
        }

        return j + 1;
    }
};

int main(void)
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> Arr(size);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> Arr[i];
    }

    cout << "Before removing duplicates: ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << endl;

    sort(Arr.begin(), Arr.end());

    Solution sobj;
    int iRet = sobj.RemoveDuplicates(Arr);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < iRet; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << endl;
    cout << "Size after Removing: " << iRet << endl;

    return 0;
}