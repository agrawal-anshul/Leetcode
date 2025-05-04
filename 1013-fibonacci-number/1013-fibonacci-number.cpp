class Solution {
    vector<int> dp;
    int fibMemoization(int n){
        if (n < 2) return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = fibMemoization(n-1) + fibMemoization(n-2);
    }
public:
    int fib(int n) {
        dp.resize(n + 1, -1);
        return fibMemoization(n);
    }
};