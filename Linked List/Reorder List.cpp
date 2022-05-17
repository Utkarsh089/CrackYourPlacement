// https://leetcode.com/problems/reorder-list/

class Solution {
public:
    ListNode* cur = NULL;
    void reorderList(ListNode* head) {
        cur = head;
        recursiveHelper(head);
    }
    void recursiveHelper(ListNode* head){
        if(head==NULL)
            return;
        recursiveHelper(head->next);
        if(cur==head){  //case1
            cur->next = NULL;
            return;
        }
        if(cur->next){
            cout<<cur->val<<" "<<head->val<<endl;
            ListNode* next = cur->next;
            cur->next = head;
            cur = cur->next;
            cur->next = next;
            cur = cur->next;
             if(cur->next==head){   //case2
                cur->next = NULL;
            }
        }
        
    }
};
