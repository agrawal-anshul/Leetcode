class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=k;j++){
                if(i+j<nums.size() && nums[i]==nums[i+j])return true;
            }
        }
        return false;
    }
};