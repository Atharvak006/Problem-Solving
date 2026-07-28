#include<stdio.h>
#include<stdlib.h>

void Merge(int *arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *list1 = (int*)malloc(n1 * sizeof(int));
    int *list2 = (int*)malloc(n2 * sizeof(int));

    int i = 0;

    while(i < n1)
    {
        list1[i] = arr[p+i];  
        i++;
    }

    i = 0;

    while(i < n2)
    {
        list2[i] = arr[q+1+i];
        i++;
    }

    i = 0;
    int j = 0, k = 0;

    while(1)
    {
        if(list1[i] <= list2[j])
        {
            arr[p+k] = list1[i];
            i++;
            k++;
            if(i == n1)
            {
                while(j < n2)
                {
                    arr[p+k] = list2[j];
                    j++;
                    k++;
                }
                break;
            }
        }
        else
        {
            arr[p+k] = list2[j];
            j++;
            k++;
            if(j == n2)
            {
                while(i < n1)
                {
                    arr[p+k] = list1[i];
                    i++;
                    k++;
                }
                break;
            }
        }
    }

}
void MergeSort(int *arr, int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
}
int main(void)
{
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);

    int *Arr = (int *)malloc(n * sizeof(int ));
    printf("Enter the elements of the array: \n");

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

    MergeSort(Arr,0,n-1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",Arr[i]);
    }

    return 0;
}