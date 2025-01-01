class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int target = 0) {
        vector<vector<int>>res;
        // As we are not concerned with the indexes and have to return the elements we can sort the original array.
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            // skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            } 
            int reqSum = target - nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum = nums[l] + nums[r];
                if(sum == reqSum){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    // skip duplicates
                    while (l < r && nums[l-1] == nums[l]) l++;
                    while (l < r && nums[r+1] == nums[r]) r--;
                }
                else if(sum<reqSum){
                        l++;
                }
                else{
                        r--;
                }
            }
        }
        return res;
    }
};