// https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
    
    void helper(TreeNode* root, string asf, vector<string> &ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(asf +  to_string(root->val));
            return;
        }
        
        if(root->left)
            helper(root->left, asf + to_string(root->val) + "->", ans);
        if(root->right)
            helper(root->right, asf + to_string(root->val) + "->", ans);
        return;
    }
};
