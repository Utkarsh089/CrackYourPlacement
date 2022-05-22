// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> s;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        s.push(root);
        while(!s.empty()){
            int n = s.size();
            vector<int> sub_ans;
            for(int i=0; i<n; i++){
                TreeNode* node = s.front();
                s.pop();
                if(node->left)  s.push(node->left);
                if(node->right)  s.push(node->right);
                sub_ans.push_back(node->val);
            }
            ans.push_back(sub_ans);
        }
        return ans;
    }
};
