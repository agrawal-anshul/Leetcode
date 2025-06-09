/*
Intuition and Key Observations:
--------------------------------
We are asked to continuously maintain the k-th largest element in a stream.
Instead of sorting or storing all elements, we can use a min-heap of size k.

A min-heap (priority queue) allows us to always keep the smallest among the
k largest elements at the top. This top element is our k-th largest value.

When a new value arrives:
- If the heap has fewer than k elements, push it directly.
- Else, compare with the heap top:
  - If it's larger than the top, it could be one of the top k values.
    Replace the top with this value.
  - Otherwise, discard it.

This ensures the heap only stores the k largest values at all times.

Why a min-heap?
- Because we want fast access to the smallest among the top k values.
- That way, any value smaller than this can be safely ignored.

Time Complexity:
----------------
- add(val): O(log k) -> since we maintain a heap of size k
- Constructor: O(n log k) where n is the size of the initial input

Space Complexity:
-----------------
- O(k): Only k elements are stored in the heap
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    // Helper method to maintain the min-heap with size at most k
    void addToHeap(int val) {
        // If heap has fewer than k elements, insert the value directly
        if (minHeap.size() < k) {
            minHeap.push(val);
        }
        // Otherwise, insert only if it's larger than the smallest among top k
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
    }

public:
    // Constructor to initialize the heap with initial values
    KthLargest(int kVal, vector<int>& nums) {
        k = kVal;

        // Add each number using the helper to enforce heap size limit
        for (int val : nums) {
            addToHeap(val);
        }
    }

    // Method to add a new value and return the current k-th largest
    int add(int val) {
        addToHeap(val);

        // The k-th largest element is at the top of the min-heap
        return minHeap.top();
    }
};

/*
Base Test Cases:
----------------
Input:
KthLargest obj(3, {4, 5, 8, 2});
obj.add(3);  // Heap: {4,5,8} -> add 3 -> ignored -> returns 4
obj.add(5);  // Heap: {4,5,8} -> add 5 -> replaces 4 -> returns 5
obj.add(10); // Heap: {5,8,10} -> add 10 -> replaces 5 -> returns 8
obj.add(9);  // Heap: {8,9,10} -> returns 8
obj.add(4);  // Heap: {8,9,10} -> 4 is ignored -> returns 8

Edge Test Cases:
----------------
1. k = 1, stream of increasing values:
   Input: KthLargest(1, {1}); add(2); -> returns 2 (always top value)

2. k = length of array:
   Input: KthLargest(4, {4, 5, 8, 2}); add(0); -> returns 2

3. all elements same:
   Input: KthLargest(2, {5,5,5}); add(5); -> returns 5

4. Negative values:
   Input: KthLargest(2, {-10, -5, -3}); add(-1); -> returns -3
*/