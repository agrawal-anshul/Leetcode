class Solution {
public:
    void backtrack(vector<string>& res, string curr, int open, int close, int n) {
        if (close == n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            backtrack(res, curr + '(', open + 1, close, n);
        }

        if (open > close) {
            backtrack(res, curr + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};