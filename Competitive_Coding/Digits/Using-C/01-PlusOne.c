#include<stdio.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int i = digitsSize - 1;

    while(i >= 0)
    {
        // if digits[i] is not 9
        if(digits[i] < 9)
        {
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }

        // else if it is 9 then 9 + 1 = 10 -> so do digits[i] = 9 and i--;
        digits[i] = 0;
        i--;
    }

    // If arr = [9,9,9] -> this below code executes
    int *result = (int *)malloc((digitsSize + 1) * sizeof(int));

    result[0] = 1;

    for(int i = 1; i < digitsSize + 1; i++){
        digits[i] = 0;
    }

    *returnSize = digitsSize + 1;

    return digits;
}
int main(void)
{
    int Size;

    printf("Enter size: ");
    scanf("%d", &Size);

    int *Arr = (int *)malloc(Size * sizeof(int));

    printf("Enter digits:\n");
    for (int i = 0; i < Size; i++)
    {
        scanf("%d", &Arr[i]);
    }

    int returnSize;
    int *iRet = plusOne(Arr, Size, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", iRet[i]);
    }
    printf("\n");

    // Free memory
    if (iRet != Arr)
        free(iRet);

    free(Arr);

    return 0;
}