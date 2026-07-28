#include <iostream>

using namespace std;

class Solution
{
public:
    bool IsPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int original = x;
        int reversed = 0;

        while (x > 0)
        {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }

        return (reversed == original);
    }
};

int main(void)
{
    int number;

    cout << "Enter the number to check: ";
    cin >> number;

    Solution sobj;

    bool bRet = sobj.IsPalindrome(number);

    if (bRet == true)
    {
        cout << "Is Palindrome..." << endl;
    }
    else
    {
        cout << "Not a Palindrome..." << endl;
    }

    return 0;
}