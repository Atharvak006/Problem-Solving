#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* Create_Node(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> next = newnode;
    newnode -> prev = newnode;
    newnode -> data = data;

    return newnode;
}

struct node* InsertFirst(struct node* head, int data)
{
    struct node* newnode = Create_Node(data);
    if(head == NULL)
    {
        return newnode;
    }

    struct node* last = head -> prev;

    newnode -> prev = last;
    newnode -> next = head;

    head -> prev = newnode;
    last -> next = newnode;
    head = newnode;

    return head;
}

struct node* InsertLast(struct node* head, int data)
{
    struct node* newnode = Create_Node(data);

    if(head == NULL)
    {
        return newnode;
    }

    struct node* last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    return head;
}

struct node* DeleteFirst(struct node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    // Only one node
    if(head->next == head)
    {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    struct node* last = head->prev;

    head = head->next;

    head->prev = last;
    last->next = head;

    free(temp);

    return head;
}

struct node* DeleteLast(struct node* head)
{
    if(head == NULL)
        return NULL;

    if(head->next == head)
    {
        free(head);
        return NULL;
    }

    struct node* last = head->prev;
    struct node* second_last = last->prev;

    second_last->next = head;
    head->prev = second_last;

    free(last);

    return head;
}

struct node* InsertAtPos(struct node* head, int iPos, int data)
{
    int cnt = Count(head);

    if(iPos < 1 || iPos > cnt + 1)
    {
        printf("Invalid position\n");
        return head;
    }

    if(iPos == 1)
    {
        return InsertFirst(head, data);
    }

    if(iPos == cnt + 1)
    {
        return InsertLast(head, data);
    }

    struct node* temp = head;
    for(int i = 1; i < iPos - 1; i++)
    {
        temp = temp -> next;
    }   

    struct node* newnode = Create_Node(data);

    temp -> next -> prev = newnode;
    newnode -> next = temp -> next;

    temp -> next = newnode;
    newnode -> prev = temp;

    return head;
}

struct node* DeleteAtPos(struct node* head, int iPos)
{
    if(head == NULL)
        return NULL;

    int cnt = Count(head);

    if(iPos < 1 || iPos > cnt)
    {
        printf("Invalid position\n");
        return head;
    }

    if(iPos == 1)
    {
        return DeleteFirst(head);
    }

    if(iPos == cnt)
    {
        return DeleteLast(head);
    }

    struct node* temp = head;

    // move to (iPos - 1)th node
    for(int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    struct node* target = temp->next;

    temp->next = target->next;
    target->next->prev = temp;

    free(target);

    return head;
}
int Count(struct node* head)
{
    if(head == NULL)
        return 0;

    struct node* temp = head;
    int count = 0;

    do{
        count++;
        temp = temp->next;
    }while(temp != head);

    return count;
}
void Display(struct node* head)
{
    struct node* temp = head;

    if(head == NULL)
    {
        printf("Linkedlist empty\n");
        return;
    }
    do
    {
        printf("|%d|->",temp -> data);
        temp = temp -> next;
    }while(temp != head);   
    printf("NULL\n");
}

int main(void)
{
    struct node* head = NULL;

    head = InsertFirst(head, 20);
    head = InsertFirst(head,10);
    Display(head);

    head = InsertLast(head,30);
    head = InsertLast(head,40);
    Display(head);

    head = DeleteFirst(head);
    Display(head);

    head = DeleteLast(head);
    Display(head);

    int iRet = Count(head);
    printf("Total Nodes = %d \n",iRet);

    head = InsertAtPos(head,2,15);
    Display(head);

    head = DeleteAtPos(head,2);
    Display(head);

    return 0;
}