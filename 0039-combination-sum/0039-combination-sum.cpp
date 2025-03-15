class Solution {
    void combinationSum(vector<int>& candidates, int idx, int target, vector<int>& selection,vector<vector<int>>& res){
        if (target < 0) {
            return;
        }
        if(target == 0){
            res.push_back(selection);
            return;
        }
    
        for(int i=idx;i<candidates.size();i++){
            if (candidates[i] > target)break;
            selection.push_back(candidates[i]);
            combinationSum(candidates,i,target-candidates[i],selection,res);
            selection.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>selection;
        combinationSum(candidates,0,target,selection,res);
        return res;
    }
};