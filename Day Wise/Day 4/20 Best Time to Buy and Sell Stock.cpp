// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini = nums[0];
        int ans = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>mini){
                ans = max(ans, nums[i]-mini);
            }
            else{
                mini = min(mini, nums[i]);
            }
        }
        return ans;
    }
};
