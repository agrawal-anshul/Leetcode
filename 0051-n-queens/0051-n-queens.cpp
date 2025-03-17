class Solution {
    bool isSafe(int row, int col, vector<string>& board, int n){
        // Check Vertically
        for(int i = row-1; i >= 0 ; i--){
            if(board[i][col] == 'Q') return false;
        }
        
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void NQueens(int n, int row, vector<string>& currRes, vector<vector<string>>&res){
        if(row == n){
            res.push_back(currRes);
            return;
        }
        for(int col=0; col < n; col++){
            if(isSafe(row, col, currRes, n)){
                currRes[row][col]='Q';
                NQueens(n, row+1, currRes, res);
                currRes[row][col]='.'; //Backtrack
            }
        }
    } 

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>currRes(n,string(n,'.'));
        NQueens(n, 0, currRes, res);       
        return res;
    }
};