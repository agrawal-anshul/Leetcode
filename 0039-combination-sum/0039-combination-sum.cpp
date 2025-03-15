class Solution {
    void combinationSum(vector<int>& candidates, int idx, int target, vector<int>& selection,vector<vector<int>>& res){
        if(idx<candidates.size()){
            if (target < 0) {
                return;
            }
            if(target == 0){
                res.push_back(selection);
                return;
            }
        
            // take
            selection.push_back(candidates[idx]);
            int newSum=target-candidates[idx];
            combinationSum(candidates,idx,newSum,selection,res);

            // not-take
            selection.pop_back();
            combinationSum(candidates,idx+1,target,selection,res);
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>selection;
        combinationSum(candidates,0,target,selection,res);

        return res;
    }
};