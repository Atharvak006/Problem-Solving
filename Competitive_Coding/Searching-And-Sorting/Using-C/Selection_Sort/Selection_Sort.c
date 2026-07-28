#include<stdio.h>
#include<stdlib.h>

void Selection_Sort(int *arr,int n)
{
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
int main(void)
{
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d\n",&n);

    int *Arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements in the array: \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&Arr[i]);
    }

    printf("Before sorting: \n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ",Arr[i]);
    }

    printf("\nAfter sorting: \n");

    Selection_Sort(Arr,n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ",Arr[i]);
    }

    return 0;
}