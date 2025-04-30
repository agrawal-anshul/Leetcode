class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // M1:Brute-Force O(n*n)
        // ====================
        // int maxLen = 0;
        // for(int i = 0; i< s.size();i++){
        //     map<char,int> mp;
        //     for(int j = i; j<s.size(); j++){
        //         if(mp.count(s[j]) == 0){
        //             int len = j-i+1;
        //             maxLen = max(len,maxLen);
        //             mp[s[j]] = j;
        //         }
        //         else{
        //             break;
        //         }

        //     }
        // }
        // return maxLen;


        // M2:Two Pointer (Sliding Window):
        // ================================
        map<char,int>mp;  //store last index of the char in the string
        int maxLen = 0;
        int l = 0, r = 0;
        while(l<=r && r<s.size()){
            char curr = s[r];
            if(mp.count(curr) != 0 && mp[curr]>=l){
                // curr is not unique.
                l = mp[curr]+1;
            }
            else{
                maxLen = max(r-l+1, maxLen);
                mp[curr] = r;
                r++;
            }
        }
        return maxLen;
    }
};