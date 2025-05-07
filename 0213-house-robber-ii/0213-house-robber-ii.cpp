class Solution {
    int rob_space_optimized(vector<int>& nums){
        int n = nums.size();

        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

        // n>=3
        int prev2 = nums[0];        // dp[i-2]
        int prev1 = max(nums[0], nums[1]); // dp[i-1]
        for(int i=2 ; i<n ; i++){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>nums1(n-1,0), nums2(n-1,0);
        // two arrays: 
            // index of nums : [0 1 2 3 4 5 ......n-2 ,n-1] => n elements 
            // nums1 will contain index 0 to n-2 elements.
            // nums2 will contain index 1 to n-1 elements.
        
        // Initialize: nums1 and nums2
        for(int i=0 ; i<n ; i++){
            if(i==0){
                nums1.push_back(nums[i]);
            }
            else if(i == n-1){
                nums2.push_back(nums[i]);
            }else{
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }

        return max(rob_space_optimized(nums1),rob_space_optimized(nums2));

    }
};