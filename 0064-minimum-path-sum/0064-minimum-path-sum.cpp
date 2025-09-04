class Solution {
public:
    int minPathSumHelper(vector<vector<int>>& grid, int& r, int& c, int curr_r, int curr_c, vector<vector<int>>&dp){
        // Out of bounds
        if (curr_r >= r || curr_c >= c) {
            return INT_MAX; // big number so min() ignores this path
        }

        // if we reach destination
        if(curr_r == r-1 && curr_c == c-1){
            return grid[curr_r][curr_c];
        }

        // Recurse right and down
        if(dp[curr_r][curr_c]!=-1)return dp[curr_r][curr_c];
        int cost_right = minPathSumHelper(grid, r, c, curr_r, curr_c + 1, dp);
        int cost_down = minPathSumHelper(grid, r, c, curr_r + 1, curr_c, dp);
        return dp[curr_r][curr_c] = grid[curr_r][curr_c] + min(cost_right, cost_down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return minPathSumHelper(grid, n, m, 0, 0, dp);
    }
};