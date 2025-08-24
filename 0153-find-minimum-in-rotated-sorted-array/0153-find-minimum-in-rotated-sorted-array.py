class Solution:
    # # -------- Iterative solution (recommended) --------
    # def findMin(self, nums: List[int]) -> int:
    #     """
    #     Find minimum in rotated sorted array (no duplicates).
    #     Time: O(log n), Space: O(1)
    #     """
    #     l, r = 0, len(nums) - 1

    #     while l < r:
    #         # If the current window [l..r] is already sorted, nums[l] is the minimum
    #         if nums[l] < nums[r]:
    #             return nums[l]

    #         m = l + (r - l) // 2

    #         # If mid element is greater than right, min must be in the right half
    #         if nums[m] > nums[r]:
    #             l = m + 1
    #         else:
    #             # Otherwise min is in left half (including mid)
    #             r = m

    #     # When l == r, we’ve narrowed it down to one element
    #     return nums[l]

    # -------- Recursive solution --------
    def findMin(self, nums: List[int]) -> int:
        """
        Wrapper for recursive helper.
        """
        return self._findMinHelper(nums, 0, len(nums) - 1)

    def _findMinHelper(self, nums: List[int], l: int, r: int) -> int:
        # Base case: single element
        if l == r:
            return nums[l]

        # If subarray is already sorted, leftmost element is the min
        if nums[l] < nums[r]:
            return nums[l]

        m = l + (r - l) // 2

        # If mid is greater than right, min lies in right half
        if nums[m] > nums[r]:
            return self._findMinHelper(nums, m + 1, r)
        else:
            # Otherwise, min lies in left half (including mid)
            return self._findMinHelper(nums, l, m)