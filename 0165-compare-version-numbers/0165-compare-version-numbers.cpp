/*
Intuition & Key Observations:
--------------------------------
We are given two version strings like "1.01", "1.001", "1.0.0" and must compare them.
Each version is composed of multiple numeric sections separated by '.'.
Two versions are compared section-by-section as integers, ignoring leading zeros.

Example:
"1.01" vs "1.001":
    -> Split into parts: [1, 1] and [1, 1]
    -> Compare each part: both are equal, hence return 0.

Key observations:
1. Leading zeros in each part do not matter (e.g., "01" = "1").
2. If one version has fewer parts, missing parts are considered zero.
3. Comparison ends at the first differing part.
4. The problem can be solved without storing all parts in arrays — 
   we can parse numbers on the fly.

Algorithm:
----------
1. Maintain two indices `i` and `j` for `version1` and `version2`.
2. At each step:
    a. Parse the next integer (skip leading zeros).
    b. Compare integers:
       - If v1_part > v2_part → return 1.
       - If v1_part < v2_part → return -1.
3. Move both pointers past the '.' delimiter.
4. If all parts are equal, return 0.

Time Complexity:
----------------
O(max(n, m))  
- We scan through both version strings at most once.

Space Complexity:
-----------------
O(1)  
- Only variables to store current integers and indices are used.

Why Efficient:
--------------
- Single pass, no extra storage, directly compares numbers as we parse them.
*/

class Solution {
private:
    // Helper to parse integer part from a given index until '.' or end
    int parsePart(const string &ver, int &idx) {
        int num = 0;

        // Read digits until '.' or end
        while (idx < (int)ver.size() and ver[idx] != '.') {
            // Build integer value digit by digit
            num = num * 10 + (ver[idx] - '0');
            idx++;
        }
        return num;
    }

public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();

        // Process parts while we have something to compare
        while (i < n1 or j < n2) {
            // Parse integer parts from current index
            int part1 = 0;
            int part2 = 0;

            if (i < n1) {
                part1 = parsePart(version1, i);
            }
            if (j < n2) {
                part2 = parsePart(version2, j);
            }

            // Compare parsed parts
            if (part1 > part2) return 1;
            if (part1 < part2) return -1;

            // Move past the '.' if not at end
            if (i < n1 and version1[i] == '.') i++;
            if (j < n2 and version2[j] == '.') j++;
        }
        return 0;
    }
};

/*
------------------------------------------------
Base Test Cases:
------------------------------------------------
1. version1 = "1.01", version2 = "1.001"
   Parsing:
       v1: 1 , 1
       v2: 1 , 1
   All parts equal → Output = 0.

2. version1 = "1.0", version2 = "1.0.0"
   Parsing:
       v1: 1 , 0
       v2: 1 , 0 , 0
   Extra zeros don't matter → Output = 0.

3. version1 = "0.1", version2 = "1.1"
   Parsing:
       v1: 0 , 1
       v2: 1 , 1
   First differing part: 0 vs 1 → Output = -1.

------------------------------------------------
Edge Test Cases:
------------------------------------------------
1. version1 = "1.0.1", version2 = "1"
   Parsing:
       v1: 1 , 0 , 1
       v2: 1 , 0
   First differing part after equal prefix: 1 vs 0 → Output = 1.

2. version1 = "1.0.0.0.0", version2 = "1"
   Parsing:
       v1: 1 , 0 , 0 , 0 , 0
       v2: 1
   All remaining parts in v1 are 0 → Output = 0.

3. version1 = "1.10", version2 = "1.2"
   Parsing:
       v1: 1 , 10
       v2: 1 , 2
   Second part: 10 vs 2 → Output = 1.
*/
