class Solution {
    void permute(vector<int>& nums,int idx,vector<vector<int>>& res){
        if(idx == nums.size()){
            res.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            permute(nums,idx+1,res);
            swap(nums[idx],nums[i]);         
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums,0,res);
        return res;
    }
};