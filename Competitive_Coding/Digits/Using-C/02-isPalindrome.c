#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(int x)
{
    int original_number = x;

    int reversed = 0;
    while(x > 0) // x != 0 is also fine.
    {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x = x / 10;
    }

    if(reversed == original_number)
    {
        return true;
    }
    
    return false;
}

int main(void)
{
    int number;
    printf("Enter the number to check: ");
    scanf("%d",&number);

    bool bret = isPalindrome(number);

    if(bret == true){
        printf("Is palindrome...\n");
    }
    else{
        printf("Not a palindrome...\n");
    }

    return 0;
}