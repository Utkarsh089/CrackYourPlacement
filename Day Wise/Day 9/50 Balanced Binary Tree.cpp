// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
    bool ans = true;
    int height(TreeNode* root){
        if(root==NULL)
            return 0 ;
        int h1 = height(root->left);
        int h2 = height(root->right);
        if(abs(h1-h2)>1)
            ans = false;
        return max(h1, h2) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};
