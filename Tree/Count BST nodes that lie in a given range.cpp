// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      if(root==NULL)
        return 0;
        
      int cnt = 0;
      if(root->data >= l && root->data <= h)
        cnt++;
      if(l < root->data)
        cnt += getCount(root->left, l, h);
      if(h > root->data)
        cnt += getCount(root->right, l, h);
      
      return cnt; 
    }
};
