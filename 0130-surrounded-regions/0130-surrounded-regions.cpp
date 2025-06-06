class Solution {
    int isValidCell(int curr_r, int curr_c, int r, int c){
        return curr_r>=0 && curr_c>=0 && curr_r < r && curr_c < c;
    }
    vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};

    void bfs(vector<vector<char>>& board, vector<vector<int>>& vis, queue<pair<int,int>>& q , int r, int c){
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int curr_r = front.first;
            int curr_c = front.second;
            for(auto [delta_r, delta_c] : directions){
                int new_r = curr_r + delta_r;
                int new_c = curr_c + delta_c;
                if(isValidCell(new_r, new_c, r, c) && board[new_r][new_c] == 'O' && !vis[new_r][new_c]){
                    vis[new_r][new_c] = 1;
                    q.push({new_r, new_c});
                }
            }
        }

    }

public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j = 0; j < c; j++){
                if(!vis[i][j]){
                    if(board[i][j]=='O' && (i == 0 || i == r-1 || j == 0 || j == c-1)){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        bfs(board, vis, q, r, c);

        for(int i=0;i<r;i++){
            for(int j = 0; j < c; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X'; 
                }
            }
        }

    }
};