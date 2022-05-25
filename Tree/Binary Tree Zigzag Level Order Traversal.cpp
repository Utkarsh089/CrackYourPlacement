// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> s;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        s.push(root);
        bool flag = 1;
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
            if(flag == 0){
                reverse(sub_ans.begin(), sub_ans.end());
                flag = 1;
            }
            else{
                flag = 0;
            }
            ans.push_back(sub_ans);
        }
        return ans;
    }
};
