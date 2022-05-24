// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(!root) return ans;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                if(i==n-1)
                    ans.push_back(node->val);
            }
        }
        return ans;
    }
};
