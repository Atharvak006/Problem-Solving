#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> PlusOne(vector<int>& digits)
    {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main(void)
{
    int Size;

    cout << "Enter size: ";
    cin >> Size;

    vector<int> Arr(Size);

    cout << "Enter digits:\n";
    for (int i = 0; i < Size; i++)
    {
        cin >> Arr[i];
    }

    Solution sobj;

    vector<int> iRet = sobj.PlusOne(Arr);

    cout << "Result: ";
    for (int i = 0; i < iRet.size(); i++)
    {
        cout << iRet[i] << " ";
    }

    cout << endl;

    return 0;
}