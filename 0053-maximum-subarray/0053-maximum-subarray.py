class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # My solution in first successful attempt
        # n = len(nums)
        # l = 0
        # r = 0
        # currSum = 0
        # maxSum = nums[0]
        # while l<=r and r<n:
        #     currSum += nums[r]
        #     if currSum > maxSum:
        #         maxSum = currSum
        #     if currSum <= 0:
        #         if r < n-1:
        #             l = r + 1
        #             currSum = 0
        #     r = r + 1
        # return maxSum

        # Kadanes Algorithm:
        # currSum = max(num, currSum + num)
        #     Either you start a new subarray at num, or continue the previous one.
        # maxSum keeps track of the best we’ve seen so far.
        maxSum = currSum = nums[0]
        for num in nums[1:]:
            currSum = max(num, currSum + num)  # restart subarray or continue
            maxSum = max(maxSum, currSum)
        return maxSum