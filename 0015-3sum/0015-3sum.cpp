class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to ensure consistent triplet ordering
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<vector<int>> uniqueTriplets;

        // Outer loop fixes one element and reduces problem to 2Sum
        for (int i = 0; i < n - 2; i++) {
            // skip duplicates for nums[i]
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            } 
            
            int target = -nums[i];
            unordered_map<int, int> mp;

            for (int j = i + 1; j < n; j++) {
                int complement = target - nums[j];

                // Check if complement already seen for this i
                if (mp.find(complement) != mp.end()) {
                    vector<int> triplet = {nums[i], nums[j], complement};
                    // sort(triplet.begin(), triplet.end());
                    uniqueTriplets.push_back(triplet); 

                    // Skip duplicates for nums[j]
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                }

                mp[nums[j]] = j; // store current num with its index
            }
        }
        return uniqueTriplets;
    }
};