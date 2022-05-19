// https://www.geeksforgeeks.org/merge-sort-for-linked-list/

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  Node* middleofthelist(Node* head){
        if(head==NULL || head->next==NULL)
            return head;
        Node* slow = new Node(0);
        slow->next = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    //function to merge two sorted lists
     Node* merge(Node* list1, Node* list2) {
        Node* list = new Node(0);
        Node* temp = list;
        while(list1 && list2){
            if(list1->data < list2->data){
                list->next = list1;
                list1 = list1->next;
            }
            else{
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }
        if(list1)
            list->next = list1;
        if(list2)
            list->next = list2;
        return temp->next;
   }
   
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
            return head;
        
        Node* middle = middleofthelist(head);
        Node* head1 = mergeSort(head);
        Node* head2 = mergeSort(middle);
        return merge(head1, head2);
    }
};



// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
