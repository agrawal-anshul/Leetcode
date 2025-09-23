class Solution:
    def _expand(self, s:str, l:int, r:int):
        n = len(s)
        res = ""
        # Expand as long as characters match
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        # l and r are one step beyond the valid palindrome
        return s[l+1:r]

    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if not s:
            return ""
        res = s[0] # at least one char is a palindrome
        for i in range(n):
            odd = self._expand(s, i, i)
            if len(odd)>len(res):
                res = odd
            
            even = self._expand(s, i, i+1)
            if len(even)> len(res):
                res = even
        return res