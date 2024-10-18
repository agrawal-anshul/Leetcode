class Solution {
private:
    void swap(int* a, int*b){
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int count=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};