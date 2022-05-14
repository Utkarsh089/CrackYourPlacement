// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
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
        
        if(list1){      //if list 1 is remaining
            list->next = list1;
        }
        
        if(list2){      //if list 2 is remaining
            list->next = list2;
        }
        
        return temp->next;
    }
};
