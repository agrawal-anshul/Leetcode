class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int res = 0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(i==digits.size()-1){
                res = digits[i]+1;
                carry = res/10;
                digits[i] = res%10;
            }else{
                if(carry==0){
                    return digits;
                }
                else{
                    res=digits[i]+carry;
                    carry = res/10;
                    digits[i] = res%10;
                }
            }
        }
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
    return digits;
    }
};