class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<unordered_set<char>> rows(row), cols(col), grids(9);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                char val = board[i][j];
                if (val == '.') continue;

                // Check row
                if (rows[i].count(val)) return false;
                rows[i].insert(val);

                // Check column
                if (cols[j].count(val)) return false;
                cols[j].insert(val);

                // Check grid
                int gridIndex = (i / 3) * 3 + (j / 3); // Calculate grid index
                if (grids[gridIndex].count(val)) return false;
                grids[gridIndex].insert(val);
            }
        }

        return true;
    }
};