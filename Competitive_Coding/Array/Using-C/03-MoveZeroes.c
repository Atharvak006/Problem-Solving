/*
    Here we use two pointer approach (left pointer and right pointer);
    we can also use brute force...by taking extra space that is an array to store all non zero elements,
    and append all the zeroes at the end of the new array.
*/

#include<stdio.h>
#include<stdlib.h>

void MoveZeroes(int *nums,int size)
{
    int left = 0;

    for(int right = 0; right < size; right++)
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
int main(void)
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Before moving: ");

    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    printf("After moving: ");

    MoveZeroes(arr,size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}