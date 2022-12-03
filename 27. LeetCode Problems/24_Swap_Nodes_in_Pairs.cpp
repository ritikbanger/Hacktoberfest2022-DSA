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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        while(p && p->next) {
            int t = p->val;
            p->val = (p->next)->val;
            (p->next)->val = t;
            p = p->next;
            if(p) p = p->next;
        }
        return head;
    }
};