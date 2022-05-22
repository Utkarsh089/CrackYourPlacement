// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

bool helper(Node* root, int min, int max){
    if(root==NULL)
        return false;
    if(root->data==min && root->data==max)
        return true;
    return helper(root->left, min, root->data-1) || helper(root->right, root->data+1, max);
}

bool isDeadEnd(Node *root)
{
    return helper(root, 1, INT_MAX);
}
