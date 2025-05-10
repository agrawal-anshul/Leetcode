class Solution {
        int tribonacciRecursive(int n){
            if(n<2){
                return 1;
            }
            if(n==2){
                return 2;
            }
            return tribonacciRecursive(n-1)+tribonacciRecursive(n-2)+tribonacciRecursive(n-3);
        };

        int tribonacciMemo(int n, vector<int>& dp){
            if(n<2){
               return dp[n] = 1;
            }

            if(dp[n]!= -1)return dp[n];

            if(n==2){
                return dp[n] = 2;
            }
            return dp[n] = tribonacciMemo(n-1, dp)+tribonacciMemo(n-2, dp)+tribonacciMemo(n-3, dp);
        };

        int tribonacciBottomUp(int n, vector<int>& dp){
            if(n<2){
               return dp[n] = 1;
            }

            if(n==2){
                return dp[n] = 2;
            }

            if(dp[n]!= -1)return dp[n];

            dp[0] = dp[1] = 1;
            dp[2] = 2;
            for(int i = 3; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
            return dp[n];
        };

        int tribonacciSpaceOptimized(int n){
            if(n<2){
               return 1;
            }
            if(n==2){
                return 2;
            }

            int prev3 = 1 , prev2 = 1;
            int prev1 = 2;
            int curr = 0;
            for(int i = 3; i<=n; i++){
                curr = prev1 + prev2 + prev3;
                
                prev3 = prev2;
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };
public:
    int tribonacci(int n) {
        //   Terms:  1 1 2 4 7 ...
        //   Index:  0 1 2 3 4 ...
        //nth term:  1 2 3 4 5 ...

        if(n==0) return 0;
        // return tribonacciRecursive(n-1);

        // vector<int>dp(n+1,-1);
        // return tribonacciMemo(n-1, dp);
        // return tribonacciBottomUp(n-1, dp);

        return tribonacciSpaceOptimized(n-1);
        

    }
};