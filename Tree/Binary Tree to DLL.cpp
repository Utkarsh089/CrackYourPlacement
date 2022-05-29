// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

class Solution
{
    private:
    Node* prev = NULL;
    Node* head = NULL;
    void inorder(Node *root){
        if(root==NULL)
            return;
        
        inorder(root->left);
        
        if(prev!=NULL){
            prev->right = root;
        }
        else{
            head = root;
        }
            
        root->left = prev;
        
        prev = root;
        
        inorder(root->right);
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        inorder(root);
        return head;
    }
    
    
};
