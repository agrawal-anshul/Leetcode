class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    // *No need to use sets as to skip duplicates. Instead we are sorting the vector and skipping over duplicate elements* 
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum = nums[j]+nums[k];
                if(nums[i]+ sum == 0)
                {
                    res.push_back({nums[i],nums[j],nums[k]});

                    // Skip duplicates for the 2nd number
                    while(j<k && nums[j]==nums[j+1])j++;
                    // Skip duplicates for the 3rd number
                    while(j<k && nums[k]==nums[k-1])k--;

                    j++;
                    k--;
                }
                else if(nums[i]+sum<0)
                {
                    j++;
                }
                else{
                    k--;
                } 
            }
            
        }
        return res;
    }
};