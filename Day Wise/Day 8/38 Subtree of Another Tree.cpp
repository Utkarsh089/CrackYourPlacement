// https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(isSame(root, subRoot))
            return true;
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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
