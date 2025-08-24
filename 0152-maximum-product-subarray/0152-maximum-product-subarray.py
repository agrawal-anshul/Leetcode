class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_so_far = min_so_far = ans = nums[0]
        for x in nums[1:]:
            temp_max = max(x, max_so_far * x, min_so_far * x)
            min_so_far = min(x, max_so_far * x, min_so_far * x)
            max_so_far = temp_max
            ans = max(ans, max_so_far)
        return ans