// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* add = new ListNode(0);
        ListNode* ans = add;
        while(l1 || l2){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            add->next = new ListNode(sum % 10);
            carry = sum / 10;
            add = add->next;
        }
        
        if(carry>0){
            add->next = new ListNode(carry);
            add = add->next;
        }
        
        return ans->next;
    }
};
