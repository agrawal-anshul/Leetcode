class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return nums[0];
        
        for (int i = 0; i < nums.size(); i += 2) {
            // Check if we are at the last element
            if (i == nums.size() - 1) {
                return nums[i]; // This is the single number
            }
            // Check if the current number is not equal to the next
            if (nums[i] != nums[i + 1]) {
                return nums[i]; // This is the single number
            }
        }
        return -1;
    }
};