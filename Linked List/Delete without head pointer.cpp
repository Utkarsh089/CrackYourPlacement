// https://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       if(del->next==NULL){
           del = NULL;
       }
       else{
           del->data = del->next->data;
           del->next = del->next->next;
       }
    }

};
