//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i = 0, k = 0, j = arr.size()-1;
        
        while(k<=j){
            if(arr[k]==0){
                swap(arr[i], arr[k]);
                i++;   
                k++;
            }
            else if(arr[k]==2){
                swap(arr[j], arr[k]);
                j--;
            }else{
                k++;
            }
        }
    }
};
