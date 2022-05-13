// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head){
            ans = ans << 1; //multiplying with base 2
            ans += head->val;
            head = head->next;
        }
        return ans;
    }
};
