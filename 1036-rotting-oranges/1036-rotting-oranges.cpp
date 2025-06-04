class Solution {
private:
    int initializeRottenOrangesAndCountFresh(vector<vector<int>>& grid, vector<vector<int>>& vis, queue< tuple<int, int, int>>& rottenQueue, int r, int c){
        int freshCount = 0;
        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    freshCount++;
                }
                else if(grid[i][j] == 2){
                    rottenQueue.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        return freshCount;
    }
    bool isValidCell(int currRow, int currCol, int rowCount, int colCount){
        if(currRow>=0 && currRow<rowCount && currCol>=0 && currCol < colCount){
            return true;
        }
        return false;
    }

    // void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,queue<pair(<int,int)>& q, int r, int c){
    // }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();

        //  tuple=> (row, col, timeInstance)
        queue<tuple<int, int, int>>rottenQueue;  
        vector<vector<int>>vis(r, vector<int>(c, 0));
       

        // STEP 1: Count the num of fresh and rotten oranges
        int rottenCount = 0;
        int freshCount = initializeRottenOrangesAndCountFresh(grid, vis, rottenQueue, r, c);
        
        if(freshCount == 0)return 0; // no fresh oranges at time 0; hence 0 is the answer
        if(rottenQueue.size() == 0 )return -1; //fresh oranges present, but no rotten oranges

        int time = 0;
        // Directions of traversal: {up, right, down, left}
        vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        
        while(!rottenQueue.empty()){
            auto [currRow, currCol, timeRotten] = rottenQueue.front();
            rottenQueue.pop();
            for(auto [deltaRow, deltaCol]: directions){
                int newRow = currRow + deltaRow;
                int newCol = currCol + deltaCol;
                if(isValidCell(newRow,newCol, r, c) && !vis[newRow][newCol] && grid[newRow][newCol]==1){
                    vis[newRow][newCol] = 1;
                    rottenQueue.push({newRow, newCol, timeRotten + 1});
                    time = max(time, timeRotten + 1);
                    freshCount--;
                    if(freshCount == 0)break;
                }
            }
        }
        if(freshCount != 0){return -1;}
        return time;
    }
};