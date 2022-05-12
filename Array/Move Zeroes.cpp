// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i = 0;
        // finding first zero
        while(i<arr.size()){
            if(arr[i]==0)
                break;
            i++;
        }
        
        int j=i+1;
        // replacing zeros with next non zero numbers
        while(j<arr.size()){
            if(arr[j]!=0){
                swap(arr[i], arr[j]);
                i++;
            }
            j++;
        }
    }
};
