class Solution {
    int rob_recursive(vector<int>& nums, int ind) {
        if(ind == 0) return nums[0];
        if(ind < 0)return 0;
        int pick = nums[ind] + rob_recursive(nums, ind -2);
        int notpick = 0 + rob_recursive(nums, ind - 1);
        return max(pick, notpick);
    }

    int rob_memoization(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + rob_memoization(nums, ind - 2, dp);
        int notpick = 0 + rob_memoization(nums, ind - 1, dp);
        return dp[ind] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (nums.size(), -1);
        // return rob_recursive(nums,n-1);
        return rob_memoization(nums,n-1,dp);


    }
};