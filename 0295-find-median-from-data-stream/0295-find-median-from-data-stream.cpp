/*
Intuition and Key Observations:
---------------------------------
The problem is to efficiently find the median of a data stream. The median is the middle 
element when the stream is sorted. If the number of elements is even, the median is the 
average of the two middle elements.

Key Approach:
- Use two heaps (priority queues) to simulate a balanced sorting structure:
  1. Max Heap (leftHeap) for the left half of the numbers.
  2. Min Heap (rightHeap) for the right half of the numbers.

Algorithm:
1. Insert the number into one of the heaps:
    - If the number is smaller than or equal to the top of the max heap, insert into leftHeap.
    - Otherwise, insert into rightHeap.
2. Balance the heaps:
    - If leftHeap has more than one extra element compared to rightHeap, move the top of
      leftHeap to rightHeap.
    - If rightHeap has more elements than leftHeap, move the top of rightHeap to leftHeap.
3. Compute the median:
    - If the heaps are of equal size, return the average of the two tops.
    - If leftHeap has one extra element, return its top.

Time Complexity:
- Insert: O(log n)
- Find Median: O(1)

Space Complexity: O(n)
*/

class MedianFinder {
private:
    priority_queue<int> leftHeap; // Max Heap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // Min Heap

    // Balances the heaps to maintain size properties
    void balanceHeaps() {
        if (leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.emplace(leftHeap.top());
            leftHeap.pop();
        } else if (rightHeap.size() > leftHeap.size()) {
            leftHeap.emplace(rightHeap.top());
            rightHeap.pop();
        }
    }

public:
    // Constructor to initialize empty heaps
    MedianFinder() {}

    // Adds a number into the data structure
    void addNum(int num) {
        if (leftHeap.empty() or num <= leftHeap.top()) {
            leftHeap.emplace(num);
        } else {
            rightHeap.emplace(num);
        }
        balanceHeaps();
    }

    // Returns the median of all elements so far
    double findMedian() {
        if (leftHeap.size() == rightHeap.size()) {
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        return leftHeap.top();
    }
};

/*
Dry Run:
---------
Case 1: Odd number of elements
addNum(3) -> leftHeap = [3], rightHeap = [] -> Median = 3
addNum(1) -> leftHeap = [1], rightHeap = [3] -> Median = (1 + 3) / 2 = 2
addNum(2) -> leftHeap = [2, 1], rightHeap = [3] -> Median = 2

Case 2: Even number of elements
addNum(5) -> leftHeap = [2, 1], rightHeap = [3, 5] -> Median = (2 + 3) / 2 = 2.5

Edge Cases:
------------
1. Single Element: Median is the element itself.
2. All Equal Elements: Median is the repeated value.
3. Sorted Increasing/Decreasing: Balancing keeps the structure valid.
4. Negative Values: Handled naturally by heaps.
5. Large Input: Efficient due to logarithmic operations.
*/
