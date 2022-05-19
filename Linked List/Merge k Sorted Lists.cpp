// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        int left = 0;
        int right = n-1;
        
        return divide_and_merge(lists, left, right);
    }
    
    ListNode* divide_and_merge(vector<ListNode*>& lists, int left, int right){
        if (left < right) {
            int mid = left + (right-left) / 2;
            ListNode* list1 = divide_and_merge(lists, left, mid);
            ListNode* list2 = divide_and_merge(lists, mid+1, right);
            return merge(list1, list2);
        }
        return lists[left];
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
