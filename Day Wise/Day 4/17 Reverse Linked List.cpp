// https://leetcode.com/problems/reverse-linked-list/


//Recursive Solution
class Solution {
public:
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


//Iterative Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head==NULL)
           return head;
        
       ListNode* dummy = NULL;
       ListNode* nextnode = head;
        
        while(head->next){
            nextnode = head->next;
            head->next = dummy;
            dummy = head;
            head = nextnode;
        }
        head->next = dummy;
        
        return head;
    }
};
