class Solution {
public:
    // Returns indices of the two numbers such that they add up to the target value
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store previously seen numbers with their indices
        unordered_map<int, int> numToIndex;

        // Iterate through each number in the array
        for (int i = 0; i < (int)nums.size(); i++) {
            // Calculate the number needed to reach the target
            int required = target - nums[i];

            // Check if required number is already seen in the map
            if (numToIndex.find(required) != numToIndex.end()) {
                // Found the pair whose sum is equal to the target
                return {numToIndex[required], i};
            }

            // Store the current number and its index for future lookup
            numToIndex[nums[i]] = i;
        }

        // If no valid pair is found, return empty vector
        return {};
    }
};

/*
Intuition and Algorithm:
- Problem: Find two distinct indices i and j in an array such that nums[i] + nums[j] = target.
- Brute force method checks all pairs (O(n^2)), but is inefficient for large arrays.
- A better solution is to use a hash map to store the number seen so far and its index.

Key Observations:
- For each number x, its complement is (target - x).
- If complement exists in the map, we found our answer.
- We store numbers as we iterate, so lookup is O(1) time.

Algorithm:
1. Initialize an empty hash map to store numbers and their indices.
2. Traverse the input array.
3. For each number, compute its complement.
4. If complement is in map, return its index and current index.
5. Otherwise, store current number and index.

Time Complexity:
- O(n): Each number is processed once, and map lookups are O(1).

Space Complexity:
- O(n): In worst case, all elements are stored in the map.

Base Test Cases:
1. nums = [2, 7, 11, 15], target = 9
   - Iteration 0: nums[0]=2 → required=7 → not in map → map={2:0}
   - Iteration 1: nums[1]=7 → required=2 → found in map → return {0,1}

2. nums = [3, 2, 4], target = 6
   - Iteration 0: nums[0]=3 → required=3 → not in map → map={3:0}
   - Iteration 1: nums[1]=2 → required=4 → not in map → map={3:0,2:1}
   - Iteration 2: nums[2]=4 → required=2 → found in map → return {1,2}

Edge Test Cases:
1. nums = [3, 3], target = 6
   - Iteration 0: nums[0]=3 → required=3 → not in map → map={3:0}
   - Iteration 1: nums[1]=3 → required=3 → found in map → return {0,1}

2. nums = [1, 2, 3], target = 7
   - No valid pair exists → return {}
*/
