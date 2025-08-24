class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for word in strs:
            key = ''.join(sorted(word))  # string works fine as key
            mp[key].append(word)
        return list(mp.values())