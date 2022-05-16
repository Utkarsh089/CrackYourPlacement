// https://leetcode.com/problems/add-two-numbers-ii/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* ans = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            int sum = carry;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            
            ans->val = sum%10;
            carry = sum/10;
            
            ListNode* dummy = new ListNode(0);
            dummy->next = ans;
            ans = dummy;
        }
        
        if(carry>0)
            ans->val = carry;
        else
            ans = ans->next;
        return ans;
    }
};
