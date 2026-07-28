#include<stdio.h>
#include<stdlib.h>

void Bubble_Sort(int *arr,int n)
{
    for(int i = 0; i < n-1; i++)
    { 
        for(int j = 0; j < n - i - 1; j++) 
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    Bubble_Sort(Arr,n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ",Arr[i]);
    }

    return 0;
}