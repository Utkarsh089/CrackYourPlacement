// https://leetcode.com/problems/path-sum-iii/

// O(n^2) solution
class Solution {
private:
    int ans = 0;
    void totalPath(TreeNode* root, long targetSum){
        if(root==NULL)  return;
        if(targetSum == root->val)  ans++;
        
        totalPath(root->left, targetSum - root->val);
        totalPath(root->right, targetSum - root->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        totalPath(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};

//O(n) solution using hashmap (Prefix Sum)
class Solution {
private:
    public:
    int pathSum(TreeNode* root, int target) {
        unordered_map<int, int> map;
        map[0] = 1;
        return totalPath(root, target, 0, map);
    }
    
    int totalPath(TreeNode* root, int target, long curSum, unordered_map<int, int> &map){
        if(root==NULL)  
            return 0;
        curSum += root->val;
        int count = 0;
        if(map.find(curSum - target) != map.end())
            count += map[curSum - target];
        
        map[curSum]++;
        count += totalPath(root->left, target, curSum, map);
        count += totalPath(root->right, target, curSum, map);
        map[curSum]--;
        return count;
    }

};
