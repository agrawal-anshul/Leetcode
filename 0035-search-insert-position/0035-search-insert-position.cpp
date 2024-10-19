class Solution {
private:
    int bsearch(vector<int>* nums,int start,int end, int target){
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(target == (*nums)[mid]){
                return mid;
            }
            else if(target < (*nums)[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = bsearch(&nums,0,nums.size()-1,target);
        if(result = -1){
            int i=0;
            while(i<nums.size() && nums[i]<target){i++;}
            return i;
        }
        return result;
        
    }
};