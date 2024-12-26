class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0;
        if(t.size()!=s.size()){return false;}
        for(;i<s.size(),j<t.size();i++,j++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};