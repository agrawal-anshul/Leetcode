class Solution {
public:
    static string toPalindromeString(string s){
        string t;
        for(const auto& a:s)
        {
            if(a>='A' && a<='Z')
            {
                t.push_back(a-'A' + 'a');
            }
            else if(a>='a' && a<='z')
            {
                t.push_back(a);
            }
            else if(a>='0' && a<='9')
            {
                t.push_back(a);
            }
        }
        return t;
    }
    bool isPalindrome(string s) {
        string s1=toPalindromeString(s);
        int len = s1.size();
        for(int i=0; i<len/2; ++i)
        {
            if(s1[i] != s1[len-i-1])
            {
                return false;
            }
        }
        return true;
    }
};