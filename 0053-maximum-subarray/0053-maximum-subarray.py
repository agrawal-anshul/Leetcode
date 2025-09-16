class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        l = 0
        r = 0
        currSum = 0
        maxSum = nums[0]
        while l<=r and r<n:
            currSum += nums[r]
            if currSum > maxSum:
                maxSum = currSum
            if currSum <= 0:
                if r < n-1:
                    l = r + 1
                    currSum = 0
            r = r + 1
        return maxSum
