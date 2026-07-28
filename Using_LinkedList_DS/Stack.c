#include<stdio.h>
#include<stdlib.h>

struct node* top = NULL;

struct node
{
    int data;
    struct node* next;
};

struct node* Create_Node(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node ));

    newnode -> next = NULL;
    newnode -> data = data;

    return newnode;

}

void Push(int data)
{
    struct node* newnode = Create_Node(data);

    if(newnode == NULL)
    {
        printf("Stack Overflow\n");
    }

    newnode -> next = top;
    top = newnode;
}

void Pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }

    struct node* temp = top;

    printf("Popped element is %d\n",top -> data);

    top = top->next;
    free(temp);
}

void Display()
{
    struct node* temp = top;

    if(top == NULL)
    {
        printf("Stack is empty\n");
    }

    while(temp != NULL)
    {
        printf("|%d| \n",temp -> data);
        temp = temp -> next;
    }

    printf("NULL\n");
}
int main()
{
    Push(10);
    Push(20);
    Push(30);

    Display();

    Pop();
    Display();

    return 0;
}