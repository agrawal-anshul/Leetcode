class Solution {
public:
    int recursiveFn(int n, vector<int>& cost){
        if(n < 0)return 0;
        if(n == 0 || n == 1)return cost[n];

        int first = recursiveFn(n-1, cost);
        int second = recursiveFn(n-2, cost);

        return cost[n] + min(first, second);
    }

    int memoFn(int n, vector<int>& dp ,vector<int>& cost){
        if(n < 0)return 0;
        if(n == 0 || n == 1)return cost[n];

        if(dp[n]!= -1)return dp[n];

        int first = recursiveFn(n-1, cost);
        int second = recursiveFn(n-2, cost);

        return dp[n] = cost[n] + min(first, second);
    }

    int bottomUpFn(int n, vector<int>& dp, vector<int>& cost){
        // dp[i] = Minimum cost required to reach step i
        
        //To reach step i, you must have come from either:
        //  Step i - 1 (pay cost[i - 1] there) 
        //          OR
        //  Step i - 2 (pay cost[i - 2] there)

        // As we can start either with 0 or 1 step:
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
    int spaceOptimizedFn(int n, vector<int>& dp, vector<int>& cost){
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr = 0;
        for(int i = 2 ; i < n ; i++){
            curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // return min(recursiveFn(n - 1, cost), recursiveFn(n - 2, cost));
        
        vector<int>dp(n, -1);
        // return min( memoFn(n-1, dp, cost), memoFn(n-2, dp, cost));
        return bottomUpFn(n, dp, cost);
    }
};