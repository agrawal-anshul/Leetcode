class Solution:
    # def maxSubArray(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     maxSum = float(-inf)
    #     i = 0
    #     j = 0
    #     currSum = 0
    #     while i<=j and i < n and j < n:
    #         currSum += nums[j]
    #         if currSum > maxSum:
    #             maxSum = currSum
    #         if currSum < 0:
    #             i = j + 1
    #             j = i
    #             currSum = 0
    #         else:
    #             j = j + 1
    #     return maxSum

    # M-2
    def maxSubArray(self, nums: List[int]) -> int:
        best = cur = nums[0]
        for x in nums[1:]:
            cur = max(x, cur + x)   # extend or restart
            best = max(best, cur)
        return best