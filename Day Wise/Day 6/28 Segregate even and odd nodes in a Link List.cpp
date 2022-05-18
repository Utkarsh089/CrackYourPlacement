// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

class Solution{
public:
    Node* divide(int N, Node *head){
        Node* odd = new Node(0);
        Node* even = new Node(0);
        Node* evenDummy = even;
        Node* oddDummy = odd;
        
        while(head){
            if(head->data % 2 == 0){
                odd->next = head;
                odd = odd->next;
            }
            else{
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        even->next = NULL; //important step
        odd->next = evenDummy->next;
        return oddDummy->next;
    }
};
