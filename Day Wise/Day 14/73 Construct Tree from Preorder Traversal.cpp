// https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1#

struct Node *helper(int n, int pre[], char preLN[], int &i)
{
    if(i>=n)
        return NULL;
    Node* root = new Node(pre[i]);
    
    if(preLN[i] == 'N'){
        i++;
        root->left = helper(n, pre, preLN, i);
        root->right = helper(n, pre, preLN, i);
    }
    else{
        i++;
         root->left=root->right=NULL;
    }
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i = 0;
    return helper(n, pre, preLN, i);
}
