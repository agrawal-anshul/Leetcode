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
            // handle duplicates
            if(i > idx && candidates[i-1] == candidates[i]){
                continue;
            }
            if (candidates[i] > target)break;
        
            // take
            selection.push_back(candidates[i]);
            combinationSum(candidates,i+1,target-candidates[i],selection,res);
            // not-take
            selection.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>selection;
        combinationSum(candidates,0,target,selection,res);
        return res;
    }
};