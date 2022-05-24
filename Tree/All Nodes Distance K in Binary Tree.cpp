// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        vector<int> ans;
        helper(target, k, parent, visited, ans);
        return ans;
    }
    
    void helper(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> &parent, unordered_set<TreeNode*> &visited, vector<int> &ans){
        if(root==NULL)
            return;
        if(visited.find(root)!=visited.end())
            return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        visited.insert(root);
        helper(root->left, k-1, parent, visited, ans);
        helper(root->right, k-1, parent, visited, ans);
        helper(parent[root], k-1, parent, visited, ans);
        return;
    }
};
