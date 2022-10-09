class Solution {
    public ListNode deleteDuplicates(ListNode temp) {
        if(temp == null)return temp;
        ListNode head = temp;
        while(temp.next != null){
            if(temp.val == temp.next.val){
                temp.next = temp.next.next;
            }else{
                temp = temp.next;
            }
            
        }
        return head;
    }
}