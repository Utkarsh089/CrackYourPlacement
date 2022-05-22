// https://leetcode.com/problems/binary-tree-inorder-traversal/

//Recursive Solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int> &nodes){
        if(root==NULL)
            return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
        return;
    }
};

//Iterative Solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(true){
            if(cur!=NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                if(stk.empty()) break;
                cur = stk.top();
                stk.pop();
                nodes.push_back(cur->val);
                cur = cur->right;
            }
        }
        return nodes;
    }
};

//Morris Traversal (Space Complexity: O(1))
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        TreeNode* cur = root;
        while(cur){
            if(cur->left==NULL){
                nodes.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right && temp->right!=cur){
                    temp = temp->right;
                }
                
                if(temp->right==NULL){
                    temp->right = cur;
                    cur = cur->left;
                }
                else{
                    temp->right = NULL;
                    nodes.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return nodes;
    }
};
