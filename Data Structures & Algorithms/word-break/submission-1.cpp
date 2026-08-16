class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> seen(wordDict.begin(), wordDict.end());
        int n = s.length(), j = 0;
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                if (dp[j] == true && seen.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
