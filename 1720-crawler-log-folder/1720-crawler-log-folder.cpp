class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (res > 0) res--;
            } else if (logs[i] == "./") {
                // Do nothing
            } else {
                res++;
            }
        }
        return res;
    }
};