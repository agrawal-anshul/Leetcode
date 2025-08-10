class Solution {
public:
    /*
    Intuition & Key Observations
    ---------------------------------
    - The degree of an array is the maximum frequency of any value.
    - The shortest subarray with the same degree must start at the first occurrence
      of some value that achieves the global degree and end at one of its later
      occurrences.
    - If we know, for each value, its first index and how many times we have seen
      it so far, then at the i-th position we can update:
        * its running count
        * the current global degree
        * the best (shortest) length when this value reaches the current degree
    - Doing this in a single left-to-right pass yields O(n) time and O(n) space.

    Algorithm (Single Pass)
    ------------------------
    1) Maintain two hash maps:
       - cnt[x]   : occurrences of value x seen so far.
       - first[x] : the first index where x appeared.
    2) Walk i from 0 to n-1:
       - If first[x] is unseen, set first[x] = i.
       - Increment cnt[x].
       - If cnt[x] > degree, update degree and set best = i - first[x] + 1.
       - Else if cnt[x] == degree, try to minimize best with i - first[x] + 1.
    3) Return best.

    Correctness Reasoning
    ---------------------
    - For any value v, every candidate subarray that preserves the array's degree
      and is based on v must start at v's first occurrence and end at one of its
      later occurrences. The moment cnt[v] meets or matches the global degree, the
      subarray [first[v], i] is valid; taking the minimal such length across all
      values and positions gives the optimal answer.

    Complexity
    ----------
    - Time:  O(n) because each element is processed once with O(1) work.
    - Space: O(n) for the maps (in the worst case, all values are distinct).
    */
    int findShortestSubArray(vector<int>& nums) {
        // Handle empty input defensively (though the problem guarantees n >= 1).
        if (nums.size() == 0) return 0;

        // Store counts for each value.
        unordered_map<int, int> cnt;
        // Store first index at which each value appears.
        unordered_map<int, int> first;

        // n = length of the input array; best initialized to the full length.
        int n = (int)nums.size();
        int degree = 0;
        int best = n;

        // Iterate through the array once, updating maps and the current answer.
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            // If this is the first time we see x, remember the index.
            if (first.find(x) == first.end()) {
                first[x] = i;
            }

            // Increase the running frequency of x.
            cnt[x] = cnt[x] + 1;

            // If x sets a strictly higher degree, reset best to this segment.
            if (cnt[x] > degree) {
                degree = cnt[x];
                best = i - first[x] + 1;
            }
            // If x ties the current degree, try to minimize the segment length.
            else if (cnt[x] == degree) {
                int cur_len = i - first[x] + 1;
                if (cur_len < best) {
                    best = cur_len;
                }
            }
        }

        // best holds the shortest subarray length that achieves the global degree.
        return best;
    }

    /*
    Base Test Cases (Dry Runs)
    ---------------------------
    1) nums = [1,2,2,3,1]
       - degree = 2 (for values 1 and 2)
       - For value 2: first[2] = 1, last at index 2 -> length = 2; best = 2
       - For value 1: first[1] = 0, last at index 4 -> length = 5; best stays 2
       - Answer = 2

    2) nums = [1]
       - degree = 1
       - first[1] = 0, at i = 0 -> best = 1
       - Answer = 1

    Edge Test Cases (Dry Runs)
    ---------------------------
    1) nums = [2,2,2,2]
       - degree climbs 1->2->3->4; best updates to 1,2,3,4 respectively
       - Answer = 4

    2) nums = [1,2,3,4]
       - degree stays 1; each subarray of a single element is valid
       - best minimized to 1
       - Answer = 1

    3) nums = [1,2,2,3,1,4,2]
       - degree = 3 (value 2), first[2] = 1, last[2] = 6 -> best = 6
       - Answer = 6
    */
};
