class Solution {
    int rob_recursive(vector<int>& nums, int ind) {
        if(ind < 0)return 0;
        if(ind == 0) return nums[0];
        int pick = nums[ind] + rob_recursive(nums, ind -2);
        int notpick = 0 + rob_recursive(nums, ind - 1);
        return max(pick, notpick);
    }

    int rob_memoization(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind < 0) return 0;
        if(ind == 0) return nums[0];
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + rob_memoization(nums, ind - 2, dp);
        int notpick = 0 + rob_memoization(nums, ind - 1, dp);
        
        return dp[ind] = max(pick, notpick);
    }

    int rob_tabulation(vector<int>&nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int i = 2; i<n ; i++){
            int pick = nums[i] + dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick , notpick);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return rob_recursive(nums,n-1);

        // vector<int> dp (nums.size(), -1);
        // return rob_memoization(nums,n-1,dp);

        return rob_tabulation(nums);

    }
};