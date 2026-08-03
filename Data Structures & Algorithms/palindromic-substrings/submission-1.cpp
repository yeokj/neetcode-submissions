class Solution {
public:
    int countSubstrings(string s) {
        string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int n = t.length(), r = 0, c = 0;
        vector<int> p(n, 0);

        for (int i = 1; i < n - 1; ++i) {
            p[i] = (i < r) ? min(r - i, p[2 * c - i]) : 0;

            while (t[i + 1 + p[i]] == t[i - 1- p[i]]) ++p[i];
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += ((p[i] + 1) / 2);
        }

        return result;
    }
};
