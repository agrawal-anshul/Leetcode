class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long q=x,r=0,reverse=0;
        while(q!=0){
            r=q%10;
            q=q/10;
            reverse=reverse*10+r;
            // cout<<reverse<<" ";
        }
        if(reverse==x) return true;
        else return false;
    }
};