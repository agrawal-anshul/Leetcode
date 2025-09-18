class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        mp = {}
        minHeap = []
        for x in nums:
            if x not in mp:
                mp[x] = 1
            else:
                mp[x] += 1
        
        for item, freq in mp.items():
            heapq.heappush(minHeap, (freq, item))
            if len(minHeap) > k:
                heapq.heappop(minHeap)
        return [item for (freq, item) in minHeap]
        