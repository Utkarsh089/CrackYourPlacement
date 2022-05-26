// https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        
        if(prev->val > root->val){
            if(first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
        cout<<first->val<<" "<<second->val;
    }
};
