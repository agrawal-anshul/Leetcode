class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                count=1;
            }
            if(count>0){
                if(nums[i]==majority)
                {
                    count++;
                }
                else{
                    count--;
                }
            }
            
            if(count==0){
                majority=nums[i];
                count++;
            }
        }
        return majority;
    }
};