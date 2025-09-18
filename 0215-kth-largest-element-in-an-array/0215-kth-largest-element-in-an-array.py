import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        minHeap = []
        for x in nums:
            if len(minHeap) < k:
                heapq.heappush(minHeap, x)
            else:
                if x > minHeap[0]:
                    heapq.heappop(minHeap)
                    heapq.heappush(minHeap, x)
        return minHeap[0]
