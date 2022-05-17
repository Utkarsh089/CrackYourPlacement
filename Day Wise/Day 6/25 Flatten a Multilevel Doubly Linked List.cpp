//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

class Solution {
public:
    Node* cur = NULL;
    Node* flatten(Node* head) {
        if(head==NULL)
            return head;
        cout<<head->val<<" ";

        
        if(cur!=NULL){
            cur->next = head;
            head->prev = cur;
        }
        cur = head;
            
        Node* next = head->next;
        
        flatten(head->child);
        head->child = NULL;
        
        flatten(next);
        return head;
    }
};
