// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* prev = new ListNode(0);
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* ans = prev;
        
        while(next){
            if(curr->val == next->val){
                while(next && curr->val == next->val){
                    next = next->next;
                }
                    prev->next = next;
            }
            
            else{
                prev->next = curr;
                prev = prev->next;
            }
            curr = next;
            if(next)
                next = next->next;
        }
        return ans->next;
    }
};
