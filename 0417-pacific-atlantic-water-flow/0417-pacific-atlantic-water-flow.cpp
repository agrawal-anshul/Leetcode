/*
PROBLEM: Pacific Atlantic Water Flow

INTUITION:
The key insight is to think backwards - instead of checking where water can flow FROM 
each cell, we check which cells can be reached FROM each ocean. Water flows from 
higher to lower heights, so we reverse this: we start from ocean boundaries and 
move to cells with equal or higher heights (reverse flow).

KEY OBSERVATIONS:
1. Pacific ocean touches the top and left borders of the grid
2. Atlantic ocean touches the bottom and right borders of the grid
3. Water can flow from a cell to adjacent cells if the adjacent cell's height is 
   less than or equal to the current cell's height
4. We need to find cells from which water can reach BOTH oceans

ALGORITHM:
1. Use DFS/BFS from all Pacific border cells to mark all reachable cells
2. Use DFS/BFS from all Atlantic border cells to mark all reachable cells  
3. Find intersection of both sets - these are cells that can reach both oceans
4. Return coordinates of all such intersection cells

TIME COMPLEXITY: O(m * n) where m = rows, n = cols
- We visit each cell at most twice (once for each ocean)
- DFS for each cell takes O(1) amortized time due to visited marking

SPACE COMPLEXITY: O(m * n) 
- Two boolean matrices for tracking reachability: O(m * n) each
- Recursion stack depth in worst case: O(m * n) for DFS
- Result vector: O(m * n) in worst case when all cells are valid
*/

class Solution {
private:
    int rows, cols;
    vector<vector<int>> heights;
    vector<vector<bool>> pacific_reachable;
    vector<vector<bool>> atlantic_reachable;
    
    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Check if given coordinates are within grid bounds
    bool is_valid_coordinate(int row, int col) {
        return row >= 0 and row < rows and col >= 0 and col < cols;
    }
    
    // DFS to mark all cells reachable from current cell for given ocean
    void mark_reachable_cells(int row, int col, vector<vector<bool>>& reachable) {
        // Mark current cell as reachable from this ocean
        reachable[row][col] = true;
        
        // Explore all 4 adjacent directions
        for (auto& dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            
            // Check if new position is valid and not already visited
            if (is_valid_coordinate(new_row, new_col) and 
                not reachable[new_row][new_col]) {
                
                // Water can flow if new cell height >= current cell height
                // (reverse flow: we're going from ocean towards higher ground)
                if (heights[new_row][new_col] >= heights[row][col]) {
                    mark_reachable_cells(new_row, new_col, reachable);
                }
            }
        }
    }
    
    // Initialize and run DFS from all Pacific border cells
    void find_pacific_reachable_cells() {
        // Start DFS from all cells in top row (Pacific border)
        for (int col = 0; col < cols; col++) {
            if (not pacific_reachable[0][col]) {
                mark_reachable_cells(0, col, pacific_reachable);
            }
        }
        
        // Start DFS from all cells in left column (Pacific border)
        for (int row = 0; row < rows; row++) {
            if (not pacific_reachable[row][0]) {
                mark_reachable_cells(row, 0, pacific_reachable);
            }
        }
    }
    
    // Initialize and run DFS from all Atlantic border cells
    void find_atlantic_reachable_cells() {
        // Start DFS from all cells in bottom row (Atlantic border)
        for (int col = 0; col < cols; col++) {
            if (not atlantic_reachable[rows - 1][col]) {
                mark_reachable_cells(rows - 1, col, atlantic_reachable);
            }
        }
        
        // Start DFS from all cells in right column (Atlantic border)
        for (int row = 0; row < rows; row++) {
            if (not atlantic_reachable[row][cols - 1]) {
                mark_reachable_cells(row, cols - 1, atlantic_reachable);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        rows = heights.size();
        cols = heights[0].size();
        
        // Initialize reachability matrices with false values
        pacific_reachable = vector<vector<bool>>(rows, vector<bool>(cols, false));
        atlantic_reachable = vector<vector<bool>>(rows, vector<bool>(cols, false));
        
        // Find all cells reachable from Pacific ocean
        find_pacific_reachable_cells();
        
        // Find all cells reachable from Atlantic ocean  
        find_atlantic_reachable_cells();
        
        // Collect all cells that can reach both oceans
        vector<vector<int>> result;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Cell is valid if it can reach both Pacific and Atlantic
                if (pacific_reachable[row][col] and atlantic_reachable[row][col]) {
                    result.push_back({row, col});
                }
            }
        }
        
        return result;
    }
};

/*
BASE TEST CASES:

Test Case 1: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Expected Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

DRY RUN:
- Grid is 5x5 with heights as given
- Pacific borders: top row [0,0] to [0,4] and left column [0,0] to [4,0]  
- Atlantic borders: bottom row [4,0] to [4,4] and right column [0,4] to [4,4]

Pacific DFS:
- From [0,0]=1: can reach [0,1]=2, [1,0]=3
- From [0,1]=2: can reach [0,2]=2, [1,1]=2  
- From [0,2]=2: can reach [0,3]=3, [1,2]=3
- From [0,3]=3: can reach [0,4]=5, [1,3]=4
- From [0,4]=5: already at border
- From [1,0]=3: can reach [2,0]=2 (NO, 2<3), [1,1]=2 (NO, 2<3)
- Continue this process...

Atlantic DFS:
- From [4,4]=4: can reach [3,4]=5, [4,3]=2 (NO, 2<4)
- From [3,4]=5: can reach [2,4]=1 (NO, 1<5), [3,3]=4 (NO, 4<5)
- Continue this process...

Final intersection gives the expected result.

Test Case 2: heights = [[1]]
Expected Output: [[0,0]]

DRY RUN:
- Single cell grid
- [0,0] is both Pacific border (top-left) and Atlantic border (bottom-right)
- Both pacific_reachable[0][0] and atlantic_reachable[0][0] will be true
- Result: [[0,0]]

EDGE TEST CASES:

Test Case 1: All cells have same height
heights = [[3,3,3],[3,3,3],[3,3,3]]
Expected Output: [[0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]]

DRY RUN:
- Since all heights are equal, water can flow between any adjacent cells
- Pacific DFS from borders will reach all cells
- Atlantic DFS from borders will reach all cells  
- All cells will be in the intersection
- Result: all 9 coordinates

Test Case 2: Monotonically increasing heights (staircase pattern)
heights = [[1,2,3],[4,5,6],[7,8,9]]

DRY RUN:  
- Pacific can only reach [0,0]=1 since all adjacent cells have higher values
- Atlantic can only reach [2,2]=9 since all adjacent cells have lower values
- No intersection possible
- Result: [] (empty)

Test Case 3: Single row
heights = [[1,3,2,4,1]]

DRY RUN:
- Pacific border: [0,0]=1
- Atlantic border: [0,4]=1  
- Pacific DFS: [0,0]=1 can reach [0,1]=3, then [0,2]=2 (NO, 2<3)
- Atlantic DFS: [0,4]=1 can reach [0,3]=4, then [0,2]=2 (NO, 2<4)
- Check each cell for intersection
- Result depends on which cells both DFS processes can reach

Test Case 4: Single column  
heights = [[1],[3],[2],[4],[1]]

DRY RUN:
- Pacific border: [0,0]=1
- Atlantic border: [4,0]=1
- Pacific DFS: [0,0]=1 can reach [1,0]=3, [2,0]=2 (NO, 2<3)  
- Atlantic DFS: [4,0]=1 can reach [3,0]=4, [2,0]=2 (NO, 2<4)
- Check intersection
- Result depends on reachability analysis
*/