#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* CreateNode(int data)
{
    struct node* newnode = (struct node* )malloc(sizeof(struct node ));

    newnode -> data = data;
    newnode -> next = NULL;

    return newnode;
}


struct node* InsertFirst(struct node* head, int data)
{
    struct node* newnode = CreateNode(data);

    if(head == NULL)
    {
        return newnode;
    }

    newnode -> next = head;
    head = newnode;

    return head;
}


struct node* Insertlast(struct node* head, int data)
{
    struct node* temp = head;
    struct node* newnode = CreateNode(data);

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newnode;
    
    return head;
}

void Display(struct node* head)
{
    struct node* temp = head;

    while(temp != NULL)
    {
        printf("|%d|->",temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

struct node* DeleteFirst(struct node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    struct node* second = head -> next;
    struct node* temp = head;

    head = second;

    free(temp);

    return head;

}


struct node* DeleteLast(struct node* head)
{
    struct node* temp = head;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    struct node* last = temp -> next;
    temp -> next = NULL;

    free(last);
    return head;
}

int main(void)
{
    struct node* head = NULL;

    head = InsertFirst(head,40);
    head = InsertFirst(head,30);
    head = InsertFirst(head,20);
    head = InsertFirst(head,10);
    
    Display(head);

    head = InsertLast(head,50);
    head = InsertLast(head,60);

    Display(head);    

    DeleteFirst(head);
    Display(head);

    DeleteLast(head);
    Display(head);

    return 0;
}