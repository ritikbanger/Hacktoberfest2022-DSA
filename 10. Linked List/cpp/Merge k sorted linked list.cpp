/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode *merge(ListNode*l1 , ListNode *l2)
    {
        ListNode *dm = new ListNode(-1);
        ListNode *curr=dm;
        
        while(l1 || l2)
        {
            if(l1== NULL)
            {
                curr->next = l2;
                return dm->next;
            }
            if(l2 == NULL){
                curr->next=l1;
                return dm->next;
            }
            if(l1->val < l2->val)
            {
                curr->next= l1;
                l1=l1->next;
            }
            else
            {
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        return dm->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()== 0)
            return NULL;
        ListNode *head = lists[0];
        for(int i=1;i< lists.size();i++)
        {
            head = merge(head , lists[i]);
        }
        return head;
    }
};

//Approach 2 : Optimal
//https://leetcode.com/problems/merge-k-sorted-lists/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //pushing all list values into min heap
        priority_queue<int, vector<int>, greater<int> > mh;
        for(auto head : lists){
            while(head){
                mh.push(head -> val);
                head = head -> next;
            }
        }

        //if there is no element in lists
        if(mh.size() == 0) return NULL;

        //creating head node of resultant list
        ListNode * head = new ListNode(mh.top());
        mh.pop();
        //we will traverse the head so storing it for returning
        ListNode * ans_head = head;

        //creating final list and poping the min heap
        int n = mh.size();
        while(n--){
            head -> next = new ListNode(mh.top());
            mh.pop();
            head = head -> next;
        }

        return ans_head;
    }
};

