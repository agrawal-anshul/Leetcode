class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Step 1: Sort the array
        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1; // Second pointer
            int k = nums.size() - 1; // Third pointer

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Step 2: Calculate the sum

                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]}); // Step 3: Found a triplet

                    // Skip duplicates for the second number
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicates for the third number
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                } else if (sum < 0) {
                    j++; // Move left pointer to increase the sum
                } else {
                    k--; // Move right pointer to decrease the sum
                }
            }
        }
        return res; // Return the result
    }
};