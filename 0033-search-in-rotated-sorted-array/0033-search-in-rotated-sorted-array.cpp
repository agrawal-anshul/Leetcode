class Solution {
public:
    int findPivot(vector<int>&nums){
        int l=0,r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;
            // Chote elements right side h
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        
        return r;
    }
    int binarySearch(vector<int>&nums,int l,int r,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int minIdx=findPivot(nums);

        if(nums[minIdx]==target) return minIdx;

        int idx=-1;
        idx=binarySearch(nums,0,minIdx-1,target); 
        if(idx!=-1) return idx;
        
        return binarySearch(nums,minIdx,nums.size()-1,target);
    }
};