// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int helper(TreeNode* root, int &ans){
        if(root==NULL)
            return 0;
        int leftsum = helper(root->left, ans);
        int rightsum = helper(root->right, ans);
        
        if(leftsum < 0) leftsum =  0;
        if(rightsum < 0) rightsum =  0;

        ans = max(ans, root->val + leftsum + rightsum);
        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};
