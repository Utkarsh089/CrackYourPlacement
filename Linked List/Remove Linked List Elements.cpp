// https://leetcode.com/problems/remove-linked-list-elements/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
         if(head == NULL)
            return head;
         
        
        ListNode* dummy = head;
        
        while(head->next){
            if(head->next->val == val){
                head->next = head->next->next;
            }
            else{
                head = head->next;
            }
        }
        
        if(dummy->val == val)
            dummy = dummy->next;
        
        return dummy;
    }
};
