#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int Minimum(int *arr, int size)
{
    int min = INT_MAX;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int Maximum(int *arr, int size)
{
    int max = INT_MIN;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main(void)
{
    int size;
    
    printf("Enter the size of the array : \n");
    scanf("%d",&size);

    int *arr = (int *)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array is : ");

    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    int iRet1 = Minimum(arr,size);
    printf("Minimum element is : %d\n",iRet1);

    int iRet2 = Maximum(arr,size);
    printf("Maximum element is : %d\n",iRet2);

    free(arr);

    return 0;
}