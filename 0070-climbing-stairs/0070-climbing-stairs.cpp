class Solution {
    int climbStairsFnTopDown(int n, vector<int>& dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = climbStairsFnTopDown(n - 1, dp) + climbStairsFnTopDown(n - 2, dp);
        return dp[n];
    }
    int climbStairsBottomUp(int n, vector<int>& dp) {
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        // return climbStairsFnTopDown(n, dp);
        return climbStairsBottomUp(n, dp);
    }
};