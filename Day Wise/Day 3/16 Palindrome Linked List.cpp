// https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* temp = head;
        
        while(temp){
            stk.push(temp->val);
            temp = temp->next;
        }
        
        while(head){
            if(head->val != stk.top())
                return false;
            head = head->next;
            stk.pop();
        }
        
        return true;
    }
};
