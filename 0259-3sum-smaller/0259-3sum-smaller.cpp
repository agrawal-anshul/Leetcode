class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long cnt = 0;
        for(int i = 0; i < n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]< target){
                    cnt+=k-j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return cnt;
    }
};
