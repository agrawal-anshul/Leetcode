/*
Intuition:
-----------
We are given two arrays:
1. gas[i]   → amount of fuel at station i
2. cost[i]  → fuel needed to travel from station i to (i+1) mod n

We need to find the starting station index from which we can travel around the circle once
without running out of fuel. If impossible, return -1.

Key Observations:
------------------
1. If the total fuel available (sum of gas) is less than total cost, the journey is
   impossible from any start point → return -1 directly.
2. If total fuel >= total cost, there is a guaranteed unique valid start point.
3. We can find it in O(n):
   - Traverse stations from left to right, maintaining `currFuel`:
       currFuel += gas[i] - cost[i]
   - If at any point `currFuel` < 0, it means we cannot reach station (i+1)
     starting from the current start index.
     So, set `startIndex = i+1` and reset currFuel = 0.
   - Continue till the end. The `startIndex` after the loop is the answer.

Why this works:
---------------
Because if we fail between two stations, any index in between cannot be a valid start:
fuel deficit before failing point will always carry over and cause failure again.

Time Complexity:
----------------
O(n) → Single traversal of both arrays.
Space Complexity:
-----------------
O(1) → Constant extra variables.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // totalNetFuel tracks total fuel gain/loss over the trip
        int totalNetFuel = 0;
        
        // currFuel tracks fuel status for the current starting attempt
        int currFuel = 0;
        
        // startIndex is the candidate starting station
        int startIndex = 0;

        // Loop through each station
        for (int i = 0; i < (int)gas.size(); i++) {
            // Net fuel at this station
            int net = gas[i] - cost[i];
            
            // Add to total fuel balance
            totalNetFuel += net;
            
            // Add to current trip's fuel
            currFuel += net;
            
            // If we run out of fuel, next station becomes new start
            if (currFuel < 0) {
                startIndex = i + 1;
                currFuel = 0;
            }
        }

        // If total fuel deficit exists, no solution
        if (totalNetFuel < 0) return -1;
        
        // Otherwise, startIndex is the valid start
        return startIndex;
    }
};

/*
------------------
Base Test Cases:
------------------
1. gas = [1,2,3,4,5], cost = [3,4,5,1,2]
   totalNetFuel = (1-3)+(2-4)+(3-5)+(4-1)+(5-2)
                 = -2 + -2 + -2 + 3 + 3 = 0
   Try start=0: fail at station 2 → start=3 works.
   Output: 3

2. gas = [2,3,4], cost = [3,4,3]
   totalNetFuel = (2-3)+(3-4)+(4-3) = -1 -1 + 1 = -1
   Negative → Output: -1

------------------
Edge Test Cases:
------------------
1. Single station, enough gas:
   gas = [5], cost = [4]
   totalNetFuel = 1 ≥ 0 → startIndex=0 works. Output: 0

2. Single station, not enough gas:
   gas = [2], cost = [3]
   totalNetFuel = -1 → Output: -1

3. All stations with exact fuel match:
   gas = [2,2,2], cost = [2,2,2]
   totalNetFuel = 0, startIndex=0 works. Output: 0
*/
