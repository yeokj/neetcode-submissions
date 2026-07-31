class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int r = 0, c = 0, n = t.length();
        vector<int> p(t.length(), 0);

        for (int i = 1; i < n; ++i) {
            if (i < r) p[i] = min(r - i, p[2 * c - i]);
            else p[i] = 0;

            while (t[i + 1 + p[i]] == t[i - 1- p[i]]) {
                ++p[i];
            }
            c = i;
            r = i + p[i];
        }

        int maxLen = 0, centerIdx = 0, start;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIdx = i;
            }
        }
        start = (centerIdx - maxLen) / 2;
        
        return s.substr(start, maxLen);
    }
};
