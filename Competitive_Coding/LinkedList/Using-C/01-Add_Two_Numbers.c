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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;

    struct ListNode* dummy = l3;
    dummy->val = 0;

    int carry = 0;

    while (l1 != NULL && l2 != NULL)
    {
        int ans = l1->val + l2->val + carry;

        struct ListNode* newnode = createNode(ans % 10);
        l3->next = newnode;
        l3 = newnode;

        carry = ans / 10;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        int ans = l1->val + carry;

        struct ListNode* newnode = createNode(ans % 10);
        l3->next = newnode;
        l3 = newnode;

        carry = ans / 10;

        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        int ans = l2->val + carry;

        struct ListNode* newnode = createNode(ans % 10);
        l3->next = newnode;
        l3 = newnode;

        carry = ans / 10;

        l2 = l2->next;
    }

    if (carry != 0)
    {
        struct ListNode* newnode = createNode(carry);
        l3->next = newnode;
    }

    return dummy->next;
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
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    l1 = InsertFirst(l1, 3);
    l1 = InsertFirst(l1, 4);
    l1 = InsertFirst(l1, 2);

    l2 = InsertFirst(l2, 4);
    l2 = InsertFirst(l2, 6);
    l2 = InsertFirst(l2, 5);

    printf("List 1: ");
    Display(l1);

    printf("List 2: ");
    Display(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    Display(result);

    return 0;
}