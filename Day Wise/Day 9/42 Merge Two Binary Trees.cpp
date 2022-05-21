// https://leetcode.com/problems/merge-two-binary-trees/

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
            return NULL;
        
        int val = 0;
        if(root1) val += root1->val;
        if(root2) val += root2->val;
        
        TreeNode* root = new TreeNode(val);
        root->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        root->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
        
        return root;
    }
};
