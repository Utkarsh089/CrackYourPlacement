//https://leetcode.com/problems/copy-list-with-random-pointer/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        
        // Inserting new nodes in between
        Node* cur = head;
        while(cur){
            Node* temp = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = temp;
            cur = temp;
        }
        
        //setting random pointers of new nodes
        cur = head;
        while(cur){
            cur->next->random = (cur->random) ? cur->random->next : NULL;
            cur = cur->next->next;
        }
        
        // seperating both the linked list
        Node* org = head;
        Node* copy = head->next;
        Node* dummy = copy;
        
        while(org){
            org->next = org->next->next;
            if(copy->next)
            copy->next = copy->next->next;
            org = org->next;
            copy = copy->next;
        }
        
        return dummy;
    }
};
