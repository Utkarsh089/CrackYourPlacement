// https://leetcode.com/problems/partition-list/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* min = new ListNode(0);
        ListNode* max = new ListNode(0);
        ListNode* maxdummy = max;
        ListNode* mindummy = min;
        
        while(head){
            if(head->val < x){
                min->next = head;
                min = min->next;
            }
            else{
                max->next = head;
                max = max->next;
            }
            head = head->next;
        }
        max->next = NULL; //important step
        min->next = maxdummy->next;
        return mindummy->next;
    }
};
