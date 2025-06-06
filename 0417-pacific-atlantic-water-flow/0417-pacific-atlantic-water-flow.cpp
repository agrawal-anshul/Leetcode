class Solution {
private:
    vector<pair<int,int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int isValidCell(int r_index, int c_index, int r, int c){
        return r_index>=0 && r_index<r && c_index>=0 && c_index<c;
    }
    void traverse(vector<vector<int>>& heights, vector<vector<bool>>& visited, int curr_r, int curr_c, int r, int c){
        visited[curr_r][curr_c] = true;
        for(auto [delta_r, delta_c]: directions){
            int new_r = curr_r + delta_r;
            int new_c = curr_c + delta_c;
            if(isValidCell(new_r, new_c, r, c) && heights[new_r][new_c]>=heights[curr_r][curr_c] && !visited[new_r][new_c]){
                traverse(heights, visited, new_r, new_c, r, c);
            }
        }
    }
    void markReachableFromPacific(vector<vector<int>>& heights, vector<vector<bool>>& reachableFromPacific, int r, int c){
        // 0th row
        for(int i = 0; i<c; i++){
            traverse(heights, reachableFromPacific, 0, i, r, c);
        }

        // 0th col
        for(int i = 0; i<r; i++){
            traverse(heights, reachableFromPacific, i, 0, r, c);
        }
    }

    void markReachableFromAtlantic(vector<vector<int>>& heights, vector<vector<bool>>& reachableFromAtlantic, int r, int c){
        // (r-1)th row
        for(int i = 0; i<c; i++){
            traverse(heights, reachableFromAtlantic, r-1, i, r, c);
        }

        // (c-1)th col
        for(int i = 0; i<r; i++){
            traverse(heights, reachableFromAtlantic, i, c-1, r, c);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>>reachableFromPacific(r, vector<bool>(c, false));
        vector<vector<bool>>reachableFromAtlantic(r, vector<bool>(c, false));
        vector<vector<int>>res;

        markReachableFromPacific(heights, reachableFromPacific, r, c);
        markReachableFromAtlantic(heights, reachableFromAtlantic, r, c);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(reachableFromPacific[i][j] && reachableFromAtlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};