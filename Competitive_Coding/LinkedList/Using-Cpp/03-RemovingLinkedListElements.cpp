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
    ListNode* RemoveElements(ListNode* head, int val)
    {
        ListNode* temp = new ListNode;
        temp->val = 0;
        temp->next = head;

        ListNode* dummy = temp;

        while (temp->next != nullptr)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }

        head = dummy->next;

        delete dummy;
        return head;
    }
};
// main:
int main()
{
    ListNode* l1 = nullptr;

    l1 = InsertFirst(l1, 6);
    l1 = InsertFirst(l1, 5);
    l1 = InsertFirst(l1, 6);
    l1 = InsertFirst(l1, 4);
    l1 = InsertFirst(l1, 3);
    l1 = InsertFirst(l1, 6);
    l1 = InsertFirst(l1, 2);
    l1 = InsertFirst(l1, 1);

    cout << "Original List: ";
    Display(l1);

    Solution sobj;

    l1 = sobj.RemoveElements(l1, 6);

    cout << "After removing 6:" << endl;
    Display(l1);

    return 0;
}