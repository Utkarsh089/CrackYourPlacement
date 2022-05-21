// https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    
    int helper(TreeNode* root, bool isLeft){
        if(root->left==NULL && root->right==NULL){
            return isLeft ? root->val : 0;
        }
        
        int sum  = 0;
        if(root->left)
            sum += helper(root->left, true);
        if(root->right)
            sum += helper(root->right, false);
        
        return sum;
    }
};
