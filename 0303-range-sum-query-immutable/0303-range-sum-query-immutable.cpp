class NumArray {
    vector<int>arr;
public:
    NumArray(vector<int>& nums) {
       arr.push_back(0);
       for(auto&x:nums){
        arr.push_back(arr.back()+x);
       }
    }
    
    int sumRange(int left, int right) {
        return arr[right+1]-arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */