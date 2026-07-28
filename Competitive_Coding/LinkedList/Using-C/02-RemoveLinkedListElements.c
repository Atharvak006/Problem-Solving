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

struct ListNode* RemoveElements(struct ListNode* head, int val)
{
    struct ListNode* temp = (struct ListNode* )malloc(sizeof(struct ListNode ));

    temp -> next = head;
    temp -> val = 0;

    struct ListNode* dummy = temp;

    while(temp -> next != NULL)
    {
        if(temp -> next -> val == val)
        {
            temp -> next = temp -> next -> next;
        }
        else
        {
            temp = temp -> next;
        }
    }

    head = dummy -> next;

    free(dummy);
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

int main(void)
{
    struct ListNode* head = NULL;

    head = InsertFirst(head, 6);
    head = InsertFirst(head, 5);
    head = InsertFirst(head, 4);
    head = InsertFirst(head, 3);
    head = InsertFirst(head, 6);
    head = InsertFirst(head, 2);
    head = InsertFirst(head, 1);

    int val = 0;
    printf("Enter the value you want to remove: ");
    scanf("%d",&val);

    printf("Before Removing: ");
    Display(head);

    struct ListNode* result = RemoveElements(head,val);

    printf("Result: ");
    Display(result);

    return 0;
}