// https://leetcode.com/problems/binary-tree-cameras/

//Approach -
//We will do post order traversal and assign camera to that node only whose child needs camera
//If any node's value is -1 means it needs camera
//If any node's value is 0 means it has camera
//If any node's value is 1 means it is covered by it's child camera
//So whenever you find any childs value 0 then assign that node a camera so that its child gets covered
//And if any node's child has value 0 means its child has camera so it doesnt require camera we will mark it as covered with value 1

class Solution {
public:
    int cameras = 0;
    int minCameraCover(TreeNode* root) {
        int value = helper(root);
        if(value==-1)
            cameras++;
        return cameras;
    }
    int helper(TreeNode* root){
        if(root==NULL)
            return 1;
        
        int lchild = helper(root->left);
        int rchild = helper(root->right);
        
        if(lchild==-1 || rchild==-1){
            cameras++;
            return 0;
        }
        if(lchild==0 || rchild==0)
            return 1;
        
        return -1;
    }
};
