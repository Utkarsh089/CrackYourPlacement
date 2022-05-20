// https://www.geeksforgeeks.org/flattening-a-linked-list/

Node* merge(Node* list1, Node* list2) {
        
        Node* list = new Node(0);
        Node* temp = list;
        
        while(list1 && list2){
            if(list1->data < list2->data){
                list->bottom = list1;
                list1 = list1->bottom;
            }
            else{
                list->bottom = list2;
                list2 = list2->bottom;
            }
            list = list->bottom;
        }
        
        if(list1){
            list->bottom = list1;
        }
        
        if(list2){
            list->bottom = list2;
        }
        
        return temp->bottom;
    }


Node *flatten(Node *head)
{
   if(head==NULL)
        return head;
    // cout<<head->data<<" ";

    Node *right = flatten(head->next);
    head->next = NULL;
    
    return merge(head, right);
    
}
