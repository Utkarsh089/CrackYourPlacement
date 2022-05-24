// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int res;
    void inorder(TreeNode* root, int& k) {
        if (!root) 
            return;
        inorder(root->left, k);
        k--;
        if (k == 0) 
            res = root->val;
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
};
