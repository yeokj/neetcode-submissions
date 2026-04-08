class Solution {
public:
    void backtrack(vector<string> &result, string p, int open, int close, int n) {
        if (p.length() == (2 * n)) {
            result.push_back(p);
            return;
        }
        if (open < n) { 
            p.push_back('(');
            backtrack(result, p, open + 1, close, n);
            p.pop_back();
        }
        if (close < open) { 
            p.push_back(')');
            backtrack(result, p, open, close + 1, n);
            p.pop_back();
        }
    }

     vector<string> generateParenthesis(int n) {
        vector<string> result;
        string p = "";
        int open = 0, close = 0;
        backtrack(result, p, open, close, n);

        return result;
    }
};
