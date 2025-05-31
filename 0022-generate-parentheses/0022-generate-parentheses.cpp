class Solution {
public:
    void backtrack(vector<string>& res, string& curr, int open, int close, int n) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(res, curr, open + 1, close, n);
            curr.pop_back();  // backtrack
        }

        if (close < open) {
            curr.push_back(')');
            backtrack(res, curr, open, close + 1, n);
            curr.pop_back();  // backtrack
        }
    }

    // M-2 mimicking recursion call stack using a stack 
    void generateParenthesisIter(int n, vector<string>& res) {
        stack<tuple<string, int, int>> stk;
        // Initial state: empty string, 0 open, 0 close parentheses
        stk.push({"", 0, 0});

        // Iterate while there are states to explore
        while (!stk.empty()) {
            // Retrieve and remove top state from the stack
            tuple<string, int, int> state = stk.top();
            stk.pop();

            string current = get<0>(state);
            int open = get<1>(state);
            int close = get<2>(state);

            // If we have used all 2n parentheses, add to result
            if (current.length() == 2 * n) {
                res.push_back(current);
                continue;
            }

            // If we can still add an open '(', push new state with one more open
            if (open < n) {
                stk.push({current + '(', open + 1, close});
            }

            // If we can add a close ')' without violating rules, push new state
            if (close < open) {
                stk.push({current + ')', open, close + 1});
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        // backtrack(res, curr, 0, 0, n);
        generateParenthesisIter(n , res);
        return res;
    }
};