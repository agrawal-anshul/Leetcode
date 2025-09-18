class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        mp = {}
        minHeap = []

        # Frequency map
        for x in nums:
            mp[x] = mp.get(x, 0) + 1

        # Min-heap of size k
        for item, freq in mp.items():
            heapq.heappush(minHeap, (freq, item))
            if len(minHeap) > k:
                heapq.heappop(minHeap)

        # Extract top k frequent elements
        return [item for (freq, item) in minHeap]