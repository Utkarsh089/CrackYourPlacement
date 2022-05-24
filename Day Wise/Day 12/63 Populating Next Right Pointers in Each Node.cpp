// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

//Using queue
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        if(!root) return root;
        
        while(!q.empty()){
            int n = q.size();
            Node* prev = NULL;
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                
                node->next = prev;
                prev = node;
            }
        }
        
        return root;
    }
};

//Without using extra space
class Solution {
public:
    Node* connect(Node* root) {
       Node* black = root;
        
        while(black && black->left){
            Node* node = black;
            while(node){
                node->left->next = node->right;
                if(node->next == NULL) 
                    break;
                node->right->next = node->next->left;
                node = node->next;
            }
            black = black->left;
        }
        
       return root;
    }
};

