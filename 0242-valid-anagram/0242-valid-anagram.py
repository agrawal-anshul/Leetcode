class Solution:
    # M-1:
    # def isAnagram(self, s: str, t: str) -> bool:
    #     return sorted(s) == sorted(t)

    # M-2
    #Counter(s) counts frequency of each character.
	#Compares both frequency maps.
    # def isAnagram(self, s: str, t: str) -> bool:
    #     return Counter(s) == Counter(t)
    
    # M-3
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        freq = {}

        # Count characters in s
        for ch in s:
            freq[ch] = freq.get(ch, 0) + 1

        # Subtract counts using t
        for ch in t:
            if ch not in freq or freq[ch] == 0:
                return False
            freq[ch] -= 1

        return True