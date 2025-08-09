// HASHING
// class Solution {
// public:
//     bool isMajorityElement(vector<int>& nums, int target) {
//         unordered_map<int,int>mp;
//         for(int i =0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         if(mp[target] > nums.size()/2){return true;}
//         return false;
//     }
// };


// Binary Search (As the array is sorted, check if:  start index + n/2 == target)
class Solution {
    int binarySearch(vector<int>& nums,int l, int r, int target){
        if (l > r) return -1;

        int m = l + (r-l)/2 ;
        int mid = nums[m];
        int ans = -1;
        if(target == mid){
            // look if theres an element before it
            ans = binarySearch(nums, l, m-1, target);
            return ans == -1 ? m : ans;
        }else if(mid > target){
            // look left
            ans = binarySearch(nums, l, m-1, target);
        }else{
            // look right
            ans = binarySearch(nums, m+1, r, target);
        }
        return ans;
    }
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int start_idx = binarySearch(nums,0,n-1, target);
        if(start_idx == -1)return false;
        if( (start_idx + n/2) < n  && nums[start_idx + n/2] == target){
            return true;
        }
    return false;
    }
};