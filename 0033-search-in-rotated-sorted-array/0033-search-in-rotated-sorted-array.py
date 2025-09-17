class Solution(object):
    def binarySearch(self, nums, target, l, r):
        while l<=r:
            m = l + (r-l) // 2
            mid = nums[m]
            if(target == mid):
                return m
            elif target > mid:
                l = m + 1
            else:
                r = m - 1
        return -1


    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        pivot = 0
        i = 0
        for i in range(n - 1):
            if nums[i] > nums[i+1]:
                pivot = i + 1
                break
        # If array not rotated, pivot will remain 0       
        
        if target >= nums[0]:
            # search before pivot
            return self.binarySearch(nums, target, 0, pivot-1 if pivot > 0 else n - 1)
        else:
            # search after pivot
            return self.binarySearch(nums, target, pivot, n-1)
            
