// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

class Solution {
public:
    int min_abs_diff = INT_MAX;
    int prev = INT_MAX;
    void dfs(TreeNode* root){
        if(root==NULL)
            return;
        dfs(root->left);
        min_abs_diff = min(min_abs_diff, abs(prev - root->val));
        prev = root->val;
        dfs(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return min_abs_diff;
    }
};
