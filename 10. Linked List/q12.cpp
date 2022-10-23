// 450dsa q12 : Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

// Function to find intersection point in Y shaped Linked Lists.
/* int length(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp->next != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *ptr1;
    Node *ptr2;
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return 1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
    }
    return -1;
} */
