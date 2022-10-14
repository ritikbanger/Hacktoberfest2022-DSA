
// Solution to the Problem : https://leetcode.com/problems/swap-nodes-in-pairs/
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
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int i = 0;
        while(current!=NULL&&i<2){
            
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
            i++;
        }
        if(next!=NULL){
            head->next = swapPairs(next);
        }
        return prev;
    }
};