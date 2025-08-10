class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int count = 0;
        int n = heights.size();
        for(int i = 0; i < n; ++i){
            if(heights[i] != expected[i]) count++;
        }
        return count;
    }
};