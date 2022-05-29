// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int n = q.size();
            vector<pair<int, int>> temp;
            
            for(int i=0; i<n; i++){
                 TreeNode* node = q.front().first;
                int col = q.front().second;

                if(node->left)  q.push({node->left, col-1});
                if(node->right)  q.push({node->right, col+1});

                temp.push_back({col, node->val});
                q.pop();
            }
            
            sort(temp.begin(), temp.end()); // first it sort by col and then by value (because if two values has same col then we have to order them by their value)
            for(auto x : temp){
                m[x.first].push_back(x.second);
            }
           
        }
        
        vector<vector<int>> ans;
        for(auto v : m){
            ans.push_back(v.second);
        }
        
        return ans;
    }
};
