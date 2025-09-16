class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # My solution in first attempt
        # SC: O(2n)
        n = len(nums)
        if n < 1:
            return []
        if n == 1:
            return [1]
            
        pre = [1] * n
        for i in range(1, n):
            pre[i] = pre[i-1] * nums[i-1]
        
        post = [1] * n
        for i in range(n-2, -1, -1):
            post[i] = post[i+1] * nums[i+1]
        
        res = []
        for i in range(n):
            res.append(pre[i] * post[i])
        return res

        # M-2: 
        # SC:O(1)
        n = len(nums)
        if n <= 1:
            return [1] * n
            
        pre = [1] * n
        for i in range(1, n):
            pre[i] = pre[i-1] * nums[i-1]
        
        res = [1] * n
        post = 1
        for i in range(n-1, -1, -1):
            res[i] = pre[i] * post
            post = post * nums[i]
        return res
        