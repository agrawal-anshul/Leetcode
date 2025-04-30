class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // M1: O(n*n)
        int maxLen = 0;
        for(int i = 0; i< s.size();i++){
            map<char,int> mp;
            for(int j = i; j<s.size(); j++){
                if(mp.count(s[j]) == 0){
                    int len = j-i+1;
                    maxLen = max(len,maxLen);
                    mp[s[j]] = j;
                }
                else{
                    break;
                }

            }
        }
        return maxLen;
    }
};