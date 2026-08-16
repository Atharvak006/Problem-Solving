#include <stdio.h>
#include <stdlib.h>

void Insertion_Sort(int *arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}

int main(void)
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *Arr = malloc(n * sizeof(int));

    if (Arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements in the array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("Before sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }

    Insertion_Sort(Arr, n);

    printf("\nAfter sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }

    printf("\n");

    free(Arr);

    return 0;
}