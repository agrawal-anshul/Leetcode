class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    bool isDuplicate(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if (nums[i] == nums[end]) return true;
        }
        return false;
    }

    void generate(int index, vector<vector<int>>& ans, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (isDuplicate(nums, index, i)) continue;
            swap(nums, index, i);
            generate(index + 1, ans, nums);
            swap(nums, index, i);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(0, ans, nums);
        return ans;
    }
};