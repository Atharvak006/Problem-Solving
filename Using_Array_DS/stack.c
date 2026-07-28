#include<stdio.h>
#include<stdlib.h>

int top = -1;
int size = 10;

void Push(int* arr, int data){

    if(top == size - 1){
        printf("Stack overflow\n");
    }

    top++;
    arr[top] = data;

}

int Pop(int* arr)
{
    if(top == -1){
        printf("stack Underflow\n");
    }    

    int iRet = arr[top];
    top--;

    return iRet;
}

int Top(int *arr)
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }

    return arr[top];
}

void Display(int* arr)
{
    for(int i = top; i >= 0; i--)
    {
        printf("|%d|\n",arr[i]);
    }
    
}
int main(void)
{
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));

    Push(arr, 10);
    Push(arr, 20);
    Push(arr, 30);

    Display(arr);

    printf("Top element = %d\n", Top(arr));

    printf("Popped = %d\n", Pop(arr));

    Display(arr);

    return 0;
}