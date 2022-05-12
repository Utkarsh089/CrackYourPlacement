//https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        
        //Floyd's Tortoise and Hare Algo
        //Linked List Cycle Detection Method
        
        int slow = arr[0];
        int fast = arr[slow];
        
        while(slow!=fast){
            slow = arr[slow];
            fast = arr[arr[fast]];
        }
        
        slow = 0;
        while(slow!=fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        
        return slow;
    }
};
