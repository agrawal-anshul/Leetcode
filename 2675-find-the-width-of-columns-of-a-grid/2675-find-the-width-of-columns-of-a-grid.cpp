class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(n, 0);
        
        for (int col = 0; col < n; ++col) {
            int maxWidth = 0;
            for (int row = 0; row < m; ++row) {
                int value = grid[row][col];
                int width = to_string(value).length();
                maxWidth = max(maxWidth, width);
            }
            result[col] = maxWidth;
        }
        
        return result;
    }
};