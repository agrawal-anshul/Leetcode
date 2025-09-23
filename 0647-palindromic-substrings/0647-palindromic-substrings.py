class Solution:
    def _expand(self, s:str, l:int, r:int) -> list[str]:
        n = len(s)
        res = []
        while l>=0 and r<n and s[l]==s[r]:
            res.append(s[l+1:r])
            l-=1
            r+=1
        return res

    def countSubstrings(self, s: str) -> int:
        if not s:return 0
        mp = {}
        n = len(s)
        count = 0
        for i in range(n):
            odd = self._expand(s,i,i)
            even = self._expand(s,i,i+1)

            for x in odd:
                mp[x] = mp.get(x, 0) + 1
            for x in even:
                mp[x] = mp.get(x, 0) + 1
        
        for x in mp:
            count += mp[x]
        
        return count

# Better Approach
# class Solution:
#     def _expand(self, s: str, l: int, r: int) -> int:
#         cnt = 0
#         n = len(s)
#         while l >= 0 and r < n and s[l] == s[r]:
#             cnt += 1
#             l -= 1
#             r += 1
#         return cnt

#     def countSubstrings(self, s: str) -> int:
#         n = len(s)
#         total = 0
#         for i in range(n):
#             total += self._expand(s, i, i)     # odd-length centers
#             total += self._expand(s, i, i + 1) # even-length centers
#         return total