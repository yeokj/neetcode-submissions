class Solution {
public:
    vector<vector<string>> result;
    bool validPalindrome(string &s, int start, int i) {
        while (start < i) {
            if (s[start] == s[i]) {
                ++start;
                --i;
            }
            else {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<string> &v, string &s, int start) {
        if (start == s.length()) {
            result.push_back(v);
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (validPalindrome(s, start, i)) {
                v.push_back(s.substr(start, i - start + 1));
                backtrack(v, s, i + 1);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        backtrack(v, s, 0);

        return result;
    }
};
