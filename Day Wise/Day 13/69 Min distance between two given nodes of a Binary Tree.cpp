// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#

class Solution{
    public:
    Node* lca(Node* root, int a, int b){
        if(root==NULL)
            return NULL;
        if(root->data==a || root->data==b)
            return root;
        
        Node* left = lca(root->left, a, b);
        Node* right = lca(root->right, a, b);
        
        if(left==NULL)    return right;
        if(right==NULL)    return left;
        
        return root;
    }
    int distance(Node* root, int a, int dist){
        if(root==NULL)
            return 0;
        if(root->data == a)
            return dist;
        
        int left = distance(root->left, a, dist + 1);
        int right = distance(root->right, a, dist + 1);
        
        // if(left==0 && right==0)
        //     return 0;
        
        return max(left , right);
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA = lca(root, a, b);
        int d1 = distance(LCA, a, 0);
        int d2 = distance(LCA, b, 0);
        
        return d1 + d2;
    }
};
