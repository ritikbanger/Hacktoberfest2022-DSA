// 450dsa q10 : Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void addAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node *reverse(node *head)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}
/*
 45
345

54
543 */
node *addTwoLists(node *first, node *second)
{
    node *head1 = reverse(first);
    node *head2 = reverse(second);
    node *dummy = new node(0);
    node *temp = dummy;
    int sum = 0;
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry)
    {
        sum = 0;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        node *newNode = new node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }
    node *ans = reverse(dummy->next);
    return ans;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        addAtTail(head1, ele);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int ele;
        cin >> ele;
        addAtTail(head2, ele);
    }
    node *newHead = addTwoLists(head1, head2);
    display(newHead);
    return 0;
}