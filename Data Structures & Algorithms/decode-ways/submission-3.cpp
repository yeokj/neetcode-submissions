class Solution {
private:
    int memo(vector<int> &dp, string s, int i, int n) {
        if (i > n) return 0;
        if (s[i] == '0') return 0;
        if (i == n) return 1;
        if (dp[i] != -1) return dp[i];

        int sl1 = memo(dp, s, i + 1, n), sl2 = 0;
        if (s.substr(i, 2) <= "26") sl2 = memo(dp, s, i + 2, n);
        
        dp[i] = sl1 + sl2;
        return dp[i];
    }

public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        
        int result = memo(dp, s, 0, n);
        return result;
    }
};
