// https://leetcode.com/problems/reverse-linked-list-ii/submissions/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // left
        ListNode* itr = dummy;
        ListNode* previtr = NULL;
        for(int i=0; i<left; i++){
            previtr = itr;
            itr = itr->next;
        }
        
        // reverse
        ListNode* prev = previtr;
        ListNode* curr = itr;
        for(int i=left; i<=right; i++){
            ListNode* forwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwd;
        }
        
        //connect
        previtr->next = prev;
        itr->next = curr;
        
        return dummy->next;
        
    }
};
