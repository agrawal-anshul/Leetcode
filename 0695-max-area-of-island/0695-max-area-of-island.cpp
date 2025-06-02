class Solution {
    private:
    int rows;
    int cols;
    
    int exploreIslandWithBacktracking(vector<vector<int>>& grid, 
                                     vector<vector<bool>>& visited, 
                                     int row, int col) {
        // Base case 1: Check if we've gone out of grid boundaries
        if (row < 0 or row >= rows or col < 0 or col >= cols) {
            return 0;
        }
        
        // Base case 2: Check if current cell is water
        if (grid[row][col] == 0) {
            return 0;
        }
        
        // Base case 3: Check if current cell is already visited
        if (visited[row][col]) {
            return 0;
        }
        
        visited[row][col] = true;
        
        int up = exploreIslandWithBacktracking(grid, visited, row - 1, col);
        
        int down = exploreIslandWithBacktracking(grid, visited, row + 1, col);
        
        int left = exploreIslandWithBacktracking(grid, visited, row, col - 1);
        
        int right = exploreIslandWithBacktracking(grid, visited, row, col + 1);

        return 1 + up + down + left + right;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return 0;
        }
        
        rows = grid.size();
        cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int totalIslands = 0;
        int maxArea = 0;
        
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentCol = 0; currentCol < cols; currentCol++) {
                // Found unvisited land - this marks the beginning of a new island
                if (grid[currentRow][currentCol] == 1 and not visited[currentRow][currentCol]) {
                    totalIslands++;
                    int area = exploreIslandWithBacktracking(grid, visited, currentRow, currentCol);
                    maxArea = max( maxArea, area );
                }
            }
        }
        
        return maxArea;
    }

};
