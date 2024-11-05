class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // actual number of rotations = k%n;
        int n=nums.size();
        k = k%n; 

        // Declare a vector of size k to store k number of elements to be moved from end;
        vector<int> temp(k);

        for(int i=0;i<k;i++){
            temp[i]=nums[n-k+i];
            // cout<<temp[i]<<" ";
        }
        for(int j=n-k-1;j>=0;j--)
        {
            nums[j+k] = nums[j];
            // cout<<nums[j+k]<<" ";
        }
        for(int y=0;y<k;y++){
            nums[y]=temp[y];
        }
    
    }
};