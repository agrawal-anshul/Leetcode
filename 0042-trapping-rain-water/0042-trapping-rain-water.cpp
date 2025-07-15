class Solution {
public:
    int trap(vector<int>& height) {
        // -------------------------------------------------------------------------
        // Intuition and Algorithm:
        // -------------------------------------------------------------------------
        // To calculate the total trapped water, we consider the water above each
        // bar individually. The amount of water above a bar is determined by the
        // minimum of the highest bars to its left and right minus the height of
        // the current bar.
        // 
        // Instead of recalculating left-max and right-max for each bar, we can 
        // precompute these values using two separate passes.
        // 
        // Steps:
        // 1. Create arrays for left-max and right-max.
        // 2. Traverse the height array to fill left-max (max height to the left).
        // 3. Traverse from right to fill right-max (max height to the right).
        // 4. Traverse each index, compute min(left-max, right-max) - height[i],
        //    and sum it to get total trapped water.
        // 
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        // -------------------------------------------------------------------------

        int n = height.size();
        if (n <= 2) {
            // Not enough bars to trap any water
            return 0;
        }

        // Initialize left-max and right-max arrays
        vector<int> left_max(n);
        vector<int> right_max(n);

        // Fill left_max: maximum height to the left of each bar (including self)
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            // Current left max is either previous max or current bar
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // Fill right_max: maximum height to the right of each bar (including self)
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // Current right max is either next max or current bar
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int total_water = 0;

        // Calculate trapped water for each bar
        for (int i = 0; i < n; i++) {
            // Water level is min of left max and right max at that point
            int water_level = min(left_max[i], right_max[i]);
            // Trapped water is the water level minus the bar height
            total_water += water_level - height[i];
        }

        return total_water;
    }

    /*
    // -------------------------------------------------------------------------
    // Alternate Solution: Two Pointers Space Optimized Approach
    // -------------------------------------------------------------------------
    // This version uses two pointers and tracks max heights from both sides.
    // Time Complexity: O(n), Space Complexity: O(1)
    // -------------------------------------------------------------------------

    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }

        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    total_water += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    total_water += right_max - height[right];
                }
                right--;
            }
        }

        return total_water;
    }
    */
};

/*
-------------------------------------------------------------------------------
Base Test Cases:
-------------------------------------------------------------------------------
1. Input: [0,1,0,2,1,0,1,3,2,1,2,1]
   Dry Run:
   - left_max:  [0 1 1 2 2 2 2 3 3 3 3 3]
   - right_max: [3 3 3 3 3 3 3 3 2 2 2 1]
   - water:     [0 0 1 0 1 2 1 0 0 1 0 0] => total = 6
   Output: 6

2. Input: [4,2,0,3,2,5]
   Dry Run:
   - left_max:  [4 4 4 4 4 5]
   - right_max: [5 5 5 5 5 5]
   - water:     [0 2 4 1 2 0] => total = 9
   Output: 9

-------------------------------------------------------------------------------
Edge Test Cases:
-------------------------------------------------------------------------------
1. Input: []
   Output: 0 (No bars)

2. Input: [3]
   Output: 0 (Single bar, no trapping possible)

3. Input: [3, 4, 5]
   Output: 0 (Increasing heights)

4. Input: [5, 4, 3]
   Output: 0 (Decreasing heights)

5. Input: [3, 0, 3]
   Output: 3 (Water trapped between two equal height bars)
*/
