#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int data)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = data;
    newnode->next = NULL;
    return newnode;
}

struct ListNode* InsertFirst(struct ListNode* head, int data)
{
    struct ListNode* newnode = createNode(data);

    newnode->next = head;
    head = newnode;

    return head;
}

void Display(struct ListNode* head)
{
    struct ListNode* temp = head;

    while (temp != NULL)
    {
        printf("|%d| -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct ListNode* RemoveDuplicates(struct ListNode* head)
{
    struct ListNode* temp = head;

    while(temp != NULL && temp -> next != NULL)
    {
        if(temp -> val == temp -> next -> val)
        {
            temp -> next = temp -> next -> next;
        }
        else
        {
            temp = temp -> next;
        }
    }

    return head;
}

int main(void)
{
    struct ListNode* l1 = NULL;

    l1 = InsertFirst(l1, 2);
    l1 = InsertFirst(l1, 1);
    l1 = InsertFirst(l1, 1);

    printf("List 1: ");
    Display(l1);

    l1 = RemoveDuplicates(l1);
    printf("After removing duplicates: \n");

    Display(l1);

    return 0;
}