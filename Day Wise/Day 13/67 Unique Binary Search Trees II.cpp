// https://leetcode.com/problems/unique-binary-search-trees-ii/

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    vector<TreeNode*> helper(int left, int right){
        vector<TreeNode*> ans;
        if(left>right){
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i=left; i<=right; i++){
            vector<TreeNode*> leftsubtree = helper(left, i-1);
            vector<TreeNode*> rightsubtree = helper(i+1, right);
            for(auto l : leftsubtree){
                for(auto r: rightsubtree){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};
