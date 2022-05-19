// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* temp = new ListNode(0);
        ListNode* prev = temp;
        temp->next = head;
        ListNode* dummy = temp;
        while(head){
            cnt++;
            if(cnt==k){
                ListNode* next = head->next;
                ListNode* temphead = head;
                
                head->next = NULL;
                ListNode* prevnext = prev->next;
                
                prev->next = reverseList(prev->next);
                
                prev = prevnext;
                prev->next = next;
                head = next;
                cnt = 0;
            }
            else{
                head = head->next;
            }
        }
        return dummy->next;
        
    }
    
     ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};
