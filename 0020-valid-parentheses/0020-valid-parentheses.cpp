class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        // int l=0,r=s.size()-1;
        // while(l<=r){
        //     if(matching[s[r]] == s[l]){
        //         l++;
        //         r--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;
        // ABOVE FAILS ON TESTCASE-> I/P: s="()[]{}"


        // Intuition and Understanding:
        // Use a stack to simulate nested structure. Push open brackets, pop and match with closing brackets.
        // If at the end the stack is empty and all matches are correct, return true.

        for(char ch:s){

            if(matching.count(ch)){
                // if closing bracket
                    // match with the top of stack
                if(st.empty() || st.top() != matching[ch])return false;
                st.pop();
            }
            else{
                //if opening bracket-> push to stack
                st.push(ch);
            }
        }
        return st.empty();
    }
};
