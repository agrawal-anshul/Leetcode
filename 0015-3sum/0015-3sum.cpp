class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int target = 0) {
        vector<vector<int>>res;
        // As we are not concerned with the indexes and have to return the elements we can sort the original array.
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            // skip duplicates for nums[i]
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            } 
            int reqSum = target - nums[i];
            
            // HASHING SOLUTION:
            unordered_map<int,int>mp;
            for(int j=i+1;j<nums.size();j++){
                int complement = reqSum-nums[j];
                if(mp.find(complement) != mp.end()){
                    res.push_back({nums[i],nums[j],complement});
                    
                    // Skip duplicates for nums[j]
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                }
                mp[nums[j]] = j;
            }

        }
        return res;
    }
};