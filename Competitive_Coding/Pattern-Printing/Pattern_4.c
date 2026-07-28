/*

*/

#include<stdio.h>

int main(void)
{
    int num_rows = 0;

    printf("Enter number of rows:");
    scanf("%d",&num_rows);

    for(int i = 0; i < num_rows; i++)
    {
        for(int j = 0; j < num_rows - i - 1; j++)
        {
            printf(" ");
        }

        for(int j = 0; j <= i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }
    
    return 0;
}