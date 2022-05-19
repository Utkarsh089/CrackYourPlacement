// https://leetcode.com/problems/sort-list/

class Solution {
public:
    ListNode* middleofthelist(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow = new ListNode(0);
        slow->next = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* middle = middleofthelist(head);
        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(middle);
        return merge(head1, head2);
    }
    
   ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* list = new ListNode();
        ListNode* temp = list;
        while(list1 && list2){
            if(list1->val < list2->val){
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
};
