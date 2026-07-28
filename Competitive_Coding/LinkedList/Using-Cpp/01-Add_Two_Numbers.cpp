#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* InsertFirst(ListNode* head, int data)
{
    ListNode* newNode = new ListNode;

    newNode->val = data;
    newNode->next = head;

    return newNode;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode;
        dummy->val = 0;
        dummy->next = nullptr;

        ListNode* temp = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;

            if (l1 != nullptr)
            {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            ListNode* newNode = new ListNode;
            newNode->val = sum % 10;
            newNode->next = nullptr;

            temp->next = newNode;
            temp = newNode;
        }

        return dummy->next;
    }
};

int main()
{
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    // First number = 243
    l1 = InsertFirst(l1, 3);
    l1 = InsertFirst(l1, 4);
    l1 = InsertFirst(l1, 2);

    // Second number = 564
    l2 = InsertFirst(l2, 4);
    l2 = InsertFirst(l2, 6);
    l2 = InsertFirst(l2, 5);

    cout << "List 1: ";
    Display(l1);

    cout << "List 2: ";
    Display(l2);

    Solution sobj;

    ListNode* result = sobj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    Display(result);

    return 0;
}