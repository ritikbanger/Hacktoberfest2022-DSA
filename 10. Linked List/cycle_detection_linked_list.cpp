//If the cycle is present the function isit will return true otherwise will return false
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

    bool isit(ListNode *head) {
        
            if(head==NULL || head->next==NULL)
                    return false;
            
            ListNode* s=head;
            ListNode* f=head;
            
            while(f->next!=NULL && f->next->next!=NULL)
            {
                    s=s->next;
                    f=f->next;
                    f=f->next;
                    if(s==f)
                            return true;
            }
            return false;
    }
