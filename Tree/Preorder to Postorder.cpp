// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1#

Node* helper(int pre[], int n, int max, int& i){
    if(i==n || pre[i] > max)
        return NULL;
    Node* root = newNode(pre[i++]);
    root->left = helper(pre, n, root->data-1, i);
    root->right = helper(pre, n, max, i);
    return root;
}

Node* post_order(int pre[], int size)
{   
    int i = 0;
    return helper(pre, size, INT_MAX, i);
}
