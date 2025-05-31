class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);  // Pre-fill with 0s

        // BRUTEFORCE:
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (temperatures[j] > temperatures[i]) {
        //             res[i] = j - i;
        //             break;
        //         }
        //     }
        // }

        // OPTIMAL:
        // Monotonic stack to hold indices
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // While the current temperature is greater than the one at top of stack
            while (!st.empty() and temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();

                // Current index is the warmer day for prevIndex
                res[prevIndex] = i - prevIndex;
            }

            // Push current index for future resolution
            st.push(i);
        }

        return res;
    }
};