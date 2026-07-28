#include <stdio.h>
#include <stdlib.h>

void SortFunction(int *Arr, int n)
{
    int temp;

    // Bubble Sort
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(Arr[i] > Arr[j])
            {
                int temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }

    printf("\nAfter Sorting:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

int RemoveDuplicates(int *Arr, int n)
{
    if(n == 0)
        return 0;

    int j = 0;

    for(int i = 1; i < n; i++)
    {
        if(Arr[i] != Arr[j])
        {
            j++;
            Arr[j] = Arr[i];
        }
    }

    return j + 1;
}

int main(void)
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *Arr = (int *)malloc(size * sizeof(int));

    if(Arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("\nElements Before Sorting:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");

    SortFunction(Arr, size);

    int newSize = RemoveDuplicates(Arr, size);

    printf("\nArray After Removing Duplicates:\n");
    for(int i = 0; i < newSize; i++)
    {
        printf("%d ", Arr[i]);
    }

    printf("\nNew Size: %d\n", newSize);

    free(Arr);

    return 0;
}