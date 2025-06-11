
// METHOD1 :HEAP
/*
Intuition & Key Observations:
--------------------------------
- We must schedule tasks with a cooldown period `n` between the same type of task.
- Our objective is to minimize the total time units taken to execute all tasks.

Key Idea:
- Use a max heap (priority queue) to always execute the task with the highest remaining frequency.
- After executing up to (n + 1) tasks, we reinsert the remaining tasks into the heap.
- If we execute fewer than (n + 1) tasks in a cycle, we must account for idle time.

Algorithm:
1. Count the frequency of each task.
2. Push all frequencies into a max heap.
3. While the heap is not empty:
   - Run a cycle of (n + 1) time units.
   - In each time unit, if a task is available, execute it and decrease its count.
   - If the count remains > 0, push it back into the heap after the cycle.
4. Count total time taken including idles.

Time Complexity: O(N * log 26) ≈ O(N)
- N is number of tasks, 26 is number of unique characters.

Space Complexity: O(26) = O(1)
- Frequency map and max heap hold at most 26 elements.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Frequency array for task counts
        int freq[26] = {0};
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        // Max heap to store frequencies
        priority_queue<int> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push(freq[i]);
            }
        }

        // Variable to store total time
        int totalTime = 0;

        // Temporary queue to hold tasks for the next cycle
        queue<int> waitQueue;

        while (!maxHeap.empty()) {
            int cycleTime = 0;

            // List to keep track of tasks to be re-added after cycle
            vector<int> toReadd;

            // Run up to (n + 1) tasks per cycle
            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    int current = maxHeap.top();
                    maxHeap.pop();

                    // Execute the task and decrement frequency
                    if (current - 1 > 0) {
                        toReadd.push_back(current - 1);
                    }
                    cycleTime++;
                }
            }

            // Reinsert remaining tasks into the heap
            for (int i = 0; i < toReadd.size(); i++) {
                maxHeap.push(toReadd[i]);
            }

            // If heap is empty, add only executed time
            // Else, add full cycle (including idle)
            if (maxHeap.empty()) {
                totalTime += cycleTime;
            } else {
                totalTime += (n + 1);
            }
        }

        return totalTime;
    }
};

/*
Base Test Cases:
------------------
1. tasks = ['A','A','A','B','B','B'], n = 2
   - Frequencies: A:3, B:3
   - Cycle 1: A, B, idle (readd A,B)
   - Cycle 2: A, B, idle (readd A,B)
   - Cycle 3: A, B → done
   - Total time = 8

2. tasks = ['A','A','A','B','B','B'], n = 0
   - No idle required → return 6

Edge Test Cases:
-------------------
1. tasks = ['A','A','A','A'], n = 3
   - Cycle 1: A, idle, idle, idle (A left: 3)
   - Cycle 2: A, idle, idle, idle (A left: 2)
   - Cycle 3: A, idle, idle, idle (A left: 1)
   - Cycle 4: A → done
   - Total time = 13

2. tasks = ['A','B','C','D','E','F'], n = 2
   - All tasks are unique, execute without idle
   - Return 6
*/














// METHOD 2: 1. Greedy with Frequency Counting (used in the implemented solution)

/*
Intuition & Key Observations:
--------------------------------
- We need to schedule tasks with a cooling period `n` between two same tasks.
- Our goal is to determine the least number of time units required to finish all tasks.

Key Idea:
- The most frequent task determines the minimum possible length of the schedule.
- Let `maxFreq` be the frequency of the most common task.
- Let `maxCount` be the number of tasks that appear `maxFreq` times.
- Visualize the most frequent task creating 'frames' of size (n + 1).
- Then fill the rest of the frame with other tasks or idle time.

Algorithm:
1. Count frequency of each task.
2. Determine the task(s) with max frequency.
3. Calculate the theoretical minimum time using:
   (maxFreq - 1) * (n + 1) + maxCount
4. Return the maximum of calculated time and total number of tasks
   (since no idle time needed if total tasks fill all slots).

Time Complexity: O(26) = O(1)
- Because we only loop over the alphabet (max 26 characters).

Space Complexity: O(26) = O(1)
- Fixed-size array to count task frequencies.
*/

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         // Frequency array to count occurrences of each task
//         int freq[26] = {0};

//         // Count frequency of each task
//         for (int i = 0; i < tasks.size(); i++) {
//             int index = tasks[i] - 'A';
//             freq[index]++;
//         }

//         // Find the highest task frequency
//         int maxFreq = 0;
//         for (int i = 0; i < 26; i++) {
//             if (freq[i] > maxFreq) {
//                 maxFreq = freq[i];
//             }
//         }

//         // Count how many tasks have frequency equal to maxFreq
//         int maxCount = 0;
//         for (int i = 0; i < 26; i++) {
//             if (freq[i] == maxFreq) {
//                 maxCount++;
//             }
//         }

//         // Calculate the minimum required slots using frame method
//         int partCount = maxFreq - 1;
//         int partLength = n + 1;
//         int minTime = partCount * partLength + maxCount;

//         // Return the max of minTime and total tasks
//         if (minTime > tasks.size()) {
//             return minTime;
//         }
//         return tasks.size();
//     }
// };

/*
Base Test Cases:
------------------
1. tasks = ['A','A','A','B','B','B'], n = 2
   - Frequency: A:3, B:3, others:0
   - maxFreq = 3, maxCount = 2
   - minTime = (3 - 1) * (2 + 1) + 2 = 8
   - Total tasks = 6 → return max(8, 6) = 8

2. tasks = ['A','A','A','B','B','B'], n = 0
   - No idle required → return tasks.size() = 6

Edge Test Cases:
-------------------
1. tasks = ['A','A','A','A'], n = 3
   - Only one type of task → All must be spaced
   - maxFreq = 4, maxCount = 1
   - minTime = (4 - 1) * (3 + 1) + 1 = 13
   - Total tasks = 4 → return max(13, 4) = 13

2. tasks = ['A','B','C','D','E','F'], n = 2
   - All unique tasks → No idle needed
   - Return 6
*/
