/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insert(struct ListNode*head,int data)
{
    struct ListNode*ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = data;
    if(head==NULL)
    {
        ptr->next=NULL;
        head = ptr;
        return head;
    }
    struct ListNode*p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next=NULL;
    return head;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *q = NULL;
    int c = 0;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    // cout<<p1->val<<p2->val<<endl;
    while (p1 != NULL && p2 != NULL)
    {
        int sum = p1->val + p2->val + c;
        // cout<<sum<<" ";
        if (sum >= 10)
        {
            c = 1;
            sum = sum % 10;
            q = insert(q, sum);
        }
        else
        {
            c = 0;
            q = insert(q, sum);
        }
        p1=p1->next;
        p2=p2->next;
    }
    // cout<<p1->val<<" "<<p2->val<<endl;
    while (p1 != NULL)
    {
        int sum = p1->val + c;
        // cout<<"in p1"<<endl;
        // cout<<sum<<" ";
        if (sum >= 10)
        {
            c = 1;
            sum = sum % 10;
            q = insert(q, sum);
        }
        else
        {
            c = 0;
            q = insert(q, sum);
        }
        p1=p1->next;
    }
    while (p2 != NULL)
    {
        int sum = p2->val + c;
        // cout<<"in p2"<<endl;
        // cout<<sum<<" ";
        if (sum >= 10)
        {
            c = 1;
            sum = sum % 10;
            q = insert(q, sum);
        }
        else
        {
            c = 0;
            q = insert(q, sum);
        }
        p2=p2->next;
    }
    if (c == 1)
    {
        q = insert(q, c);
    }
    return q;
}
