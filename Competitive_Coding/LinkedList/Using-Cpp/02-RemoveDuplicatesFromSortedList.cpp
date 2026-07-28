#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* CreateNode(int data)
{
    ListNode* newNode = new ListNode;

    newNode->val = data;
    newNode->next = nullptr;

    return newNode;
}

ListNode* InsertFirst(ListNode* head, int data)
{
    ListNode* newNode = CreateNode(data);

    newNode->next = head;
    head = newNode;

    return head;
}

void Display(ListNode* head)
{
    while (head != nullptr)
    {
        cout << "|" << head->val << "| -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

class Solution
{
public:
    ListNode* RemoveDuplicates(ListNode* head)
    {
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main()
{
    ListNode* l1 = nullptr;

    l1 = InsertFirst(l1, 2);
    l1 = InsertFirst(l1, 1);
    l1 = InsertFirst(l1, 1);

    cout << "List 1: ";
    Display(l1);

    Solution sobj;

    l1 = sobj.RemoveDuplicates(l1);

    cout << "After removing duplicates:" << endl;
    Display(l1);

    return 0;
}