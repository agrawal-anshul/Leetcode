class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i + 1}; // Return 1-based indices
            }

            // Add the current number to the map
            mp[numbers[i]] = i + 1; // Store 1-based index
        }

        return {}; 
    }
};