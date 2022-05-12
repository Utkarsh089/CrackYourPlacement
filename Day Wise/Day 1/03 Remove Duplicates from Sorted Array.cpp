// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 1;
        
        while(j<n){
            if(arr[i]<arr[j]){
                i++;
                arr[i] = arr[j];
            }
          j++;
        }
        return i+1;
    }
};
