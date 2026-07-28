/*
    ****
    ***
    **
    *
*/

#include<stdio.h>

int main(void)
{
    int num_rows = 0;

    printf("Enter number of rows:");
    scanf("%d",&num_rows);

    for(int i = num_rows - 1; i >= 0; i--)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}