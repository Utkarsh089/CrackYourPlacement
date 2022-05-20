// https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        invertTree(root->right);
        return isSame(root->left, root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
    
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL)
            return true;
        if(root==NULL || subRoot==NULL)
            return false;
        if(root->val != subRoot->val)
            return false;
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};
