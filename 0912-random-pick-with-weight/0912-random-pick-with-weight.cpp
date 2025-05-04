class Solution {
    vector<int> prefix;
    int total;

    // Helper: binary search for first index such that prefix[i] >= target
    int findIndex(int target) {
        int left = 0;
        int right = (int)prefix.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

public:
    // Constructor: build prefix sum
    Solution(vector<int>& w) {
        int n = (int)w.size();
        prefix.resize(n);
        prefix[0] = w[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        total = prefix[n - 1];
        srand((unsigned)time(nullptr));
    }

    // Randomly pick index based on weight
    int pickIndex() {
        int target = (rand() % total) + 1;
        return findIndex(target);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */