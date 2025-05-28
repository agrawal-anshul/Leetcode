class Solution {
public:
    int findMinHelper(vector<int>& nums, int l, int r){
        if(l > r)return -1;

        // If the array is already sorted with no rotation
        if (nums[l] <= nums[r]) {
            return nums[l];
        }

        int mid = l + (r-l)/2;
        if(nums[mid] < nums[r]){
            // look left
            return findMinHelper(nums, l, mid);
        }
        else{
            return findMinHelper(nums, mid+1, r);
        }
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return findMinHelper(nums, 0, n-1);
    }
};