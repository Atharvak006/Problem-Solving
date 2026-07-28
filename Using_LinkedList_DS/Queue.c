#include<stdio.h>
#include<stdlib.h>

struct node* front = NULL;
struct node* rear = NULL;

struct node
{
    int data;
    struct node* next;
};

struct node* CreateNode(int data)
{
    struct node* newnode = (struct node* )malloc(sizeof(struct node));
    newnode -> next = NULL;
    newnode -> data = data;

    return newnode;
}
void Enqueue(int data)
{
    struct node* newnode = CreateNode(data);

    if(rear == NULL && front == NULL)
    {
        front = rear = newnode;
    }

    else{
        rear -> next = newnode;
        rear = newnode;
    }
}


void Dequeue()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct node* temp = front;

    printf("Dequeued element is %d\n", front -> data);

    front = front -> next;

    if(front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}

void Display()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    
    struct node* temp = front;

    while(temp != NULL)
    {
        printf("|%d| -> ",temp -> data);
        temp = temp -> next;
    }

    printf("NULL\n");
}
int main(void)
{

    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);

    Display();

    Dequeue();
    Display();

    return 0;
}