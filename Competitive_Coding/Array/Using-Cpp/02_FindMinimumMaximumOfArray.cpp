#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int Minimum(vector<int>& arr)
    {
        int min = INT_MAX;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }

        return min;
    }

    int Maximum(vector<int>& arr)
    {
        int max = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        return max;
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

    cout << "Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << endl;

    Solution sobj;

    int iRet1 = sobj.Minimum(Arr);
    cout << "Minimum element is: " << iRet1 << endl;

    int iRet2 = sobj.Maximum(Arr);
    cout << "Maximum element is: " << iRet2 << endl;

    return 0;
}