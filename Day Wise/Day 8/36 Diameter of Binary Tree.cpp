// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
    
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        diameter = max(diameter, (leftHeight+rightHeight));
        
        return max(leftHeight, rightHeight) + 1;
    }
};
