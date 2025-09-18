import heapq
class Solution(object):
    # # mysolution:
    # def findKthLargest(self, nums, k):
    #     """
    #     :type nums: List[int]
    #     :type k: int
    #     :rtype: int
    #     """
    #     minHeap = []
    #     for x in nums:
    #         if len(minHeap) < k:
    #             heapq.heappush(minHeap, x)
    #         else:
    #             if x > minHeap[0]:
    #                 heapq.heappop(minHeap)
    #                 heapq.heappush(minHeap, x)
    #     return minHeap[0]

    # better solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        min_heap = []
        
        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        
        return min_heap[0]
