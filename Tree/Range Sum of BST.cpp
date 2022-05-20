// https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return 0;
        
        int sum =  0;
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
        if(root->val >= low && root->val <= high)
            sum += root->val;
        
        return sum;
    }
};
