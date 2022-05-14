// https://leetcode.com/problems/intersection-of-two-linked-lists/


public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a || b){
            if(a==b)
                return a;
            
            if(a){
                a = a->next;
            }
            else{
                a = headB;
            }
            
            if(b){
                b = b->next;
            }
            else{
                b = headA;
            }
        }
        
        return NULL;
        
    }
};



//By doing modification in the values of nodes
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans = NULL;
        ListNode* temp = headA;
        
        while(headA){
            headA->val *= -1;
            headA = headA->next;
        }
        
        while(headB){
            if(headB->val < 0){
                ans = headB;
                break;
            }
            headB = headB->next;
        }
        
        headA = temp;
        while(headA){
            headA->val *= -1;
            headA = headA->next;
        }
        
        return ans;
    }
};
