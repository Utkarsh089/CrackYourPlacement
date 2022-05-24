// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

class Solution {
public:
    int i = 0, j = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[i]);
        
        if(root->val != postorder[j]){
            i++;
            root->left = constructFromPrePost(preorder, postorder);
        }

        
         if(root->val != postorder[j]){
            i++;
            root->right = constructFromPrePost(preorder, postorder);
        }

        j++;
        return root;
        
    }
};
