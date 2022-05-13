// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* dummy = head;
        while(head->next){
            if(head->val == head->next->val){
                head->next = head->next->next;
            }
            else{
                head = head->next;
            }
        }
        return dummy;
    }
};
