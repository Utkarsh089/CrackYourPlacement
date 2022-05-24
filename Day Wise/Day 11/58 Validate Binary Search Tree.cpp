// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        
        if(!isValidBST(root->left))
            return false;
        
        if(prev!=NULL)
            if(prev->val >= root->val)
                return false;
        prev = root;
        
        if(!isValidBST(root->right))
            return false;
        
        return true;
    }
};
