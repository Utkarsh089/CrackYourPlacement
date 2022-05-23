// https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        
        int ans = 1;
        while(!q.empty()){
            int n = q.size();
            int left = INT_MAX, right = INT_MIN;
            int mini = q.front().second;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front().first;
                unsigned int curr = q.front().second - mini;
                q.pop();
                if(node->left)   q.push({node->left, 2*curr + 1});
                if(node->right)  q.push({node->right, 2*curr + 2});
                if(i==0) left = curr;
                if(i==n-1) right = curr;
            }
            if(left!=INT_MAX && right!=INT_MIN)
                ans = max(ans, right-left+1);
        }
        return ans;
    }
};
