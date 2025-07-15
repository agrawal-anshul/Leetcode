// // Leetcode 63 - Unique Paths II - Multiple Methods (C++23)
// // Method M1: Pure Recursion (Exponential Time)
// class Solution_M1 {
// public:
//     int solve(int i, int j, vector<vector<int>>& grid) {
//         if (i < 0 or j < 0 or grid[i][j] == 1) return 0;
//         if (i == 0 and j == 0) return 1;
//         return solve(i - 1, j, grid) + solve(i, j - 1, grid);
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int rows = (int)grid.size();
//         int cols = (int)grid[0].size();
//         return solve(rows - 1, cols - 1, grid);
//     }
// };

// // Method M2: Recursion + Memoization (Top-Down DP)
// class Solution_M2 {
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
//         if (i < 0 or j < 0 or grid[i][j] == 1) return 0;
//         if (i == 0 and j == 0) return 1;
//         if (memo[i][j] != -1) return memo[i][j];
//         return memo[i][j] = solve(i - 1, j, grid, memo) + solve(i, j - 1, grid, memo);
//     }

// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int rows = (int)grid.size();
//         int cols = (int)grid[0].size();
//         vector<vector<int>> memo(rows, vector<int>(cols, -1));
//         return solve(rows - 1, cols - 1, grid, memo);
//     }
// };

// // Method M3: Bottom-Up DP (2D Table)
// class Solution_M3 {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int rows = (int)grid.size();
//         int cols = (int)grid[0].size();
//         vector<vector<int>> dp(rows, vector<int>(cols, 0));

//         if (grid[0][0] == 0) dp[0][0] = 1;

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (grid[i][j] == 1) continue;
//                 if (i > 0) dp[i][j] += dp[i - 1][j];
//                 if (j > 0) dp[i][j] += dp[i][j - 1];
//             }
//         }

//         return dp[rows - 1][cols - 1];
//     }
// };

// Method M4: Bottom-Up DP (1D Space Optimized) [Most Optimized]
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        vector<int> dp(cols, 0);

        dp[0] = (grid[0][0] == 0) ? 1 : 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }

        return dp[cols - 1];
    }
};
