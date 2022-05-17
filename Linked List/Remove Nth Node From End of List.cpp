// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = dummy;
        
        for(int i=0; i<n; i++){
            if(right->next)
                right = right->next;
            else
                return head;
        }

        while(right->next){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
            return dummy->next;
    }
    
};
