class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>freq;
        int maxFreq = 0;
        int maxLen = 0;
        int l = 0, r = 0;
        while(l <= r && r < s.size() ){
            freq[s[r]]++;
            maxFreq = max(maxFreq,freq[s[r]]);
            if((r - l + 1) - maxFreq > k){
                //shrink the window from the left (till k is regained)
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, (r - l + 1));
            r++;
        }
        return maxLen;
    }
};