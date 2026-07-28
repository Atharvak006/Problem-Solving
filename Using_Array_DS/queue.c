#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear = -1;
int size = 10;

void Enqueue(int *arr, int data)
{
    if(rear == size - 1)
    {
        printf("Queue overflow\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    arr[rear] = data;
}

int Dequeue(int *arr)
{
    if(front == -1 || front > rear)
    {
        printf("Queue underflow\n");
        return -1;
    }

    int val = arr[front];
    front++;

    return val;
}

int Front(int *arr)
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }

    return arr[front];
}

void Display(int *arr)
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
    {
        printf("|%d| ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int *arr = (int *)malloc(size * sizeof(int));

    Enqueue(arr,10);
    Enqueue(arr,20);
    Enqueue(arr,30);
    Enqueue(arr,40);

    Display(arr);

    int iRet = Dequeue(arr);
    printf("Dequeued element is %d\n", iRet);

    Display(arr);

    int frontElement = Front(arr);
    printf("Front element is %d\n", frontElement);

    Display(arr);

    return 0;
}