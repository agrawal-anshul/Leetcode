class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int currStreak = 1;
        int maxStreak = INT_MIN;
        for(auto i:nums){
            s.insert(i);
        }
        for(auto i:s){
            currStreak = 1;
            // if a smaller number than i is not found, i can be the start of the sequence;
            if(s.find(i-1) == s.end()){
                while(s.find(i+1) != s.end()){
                    currStreak++;
                    i++;
                }
                maxStreak = max(maxStreak,currStreak);
            }
        }
        return (maxStreak<0)?0:maxStreak;
    }
};