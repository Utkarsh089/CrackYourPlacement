// https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

class Solution
{
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
       if(head->next==NULL)
        return head;
        
      Node* node = head;
      bool flag = true;
      while(node->next){
          if(flag){
              if(node->data > node->next->data){
                  int temp = node->data;
                  node->data = node->next->data;
                  node->next->data = temp;
              }
              flag = false;
          }
          else{
              if(node->data < node->next->data){
                  int temp = node->data;
                  node->data = node->next->data;
                  node->next->data = temp;
              }
              flag = true;
          }
          node = node->next;
      }
      return head;
    }
};
