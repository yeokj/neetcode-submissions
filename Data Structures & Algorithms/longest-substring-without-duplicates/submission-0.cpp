class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int maxPrefix = 0;
        int i = 0;

        for (int j = 0; j < s.length(); ++j) {
            ++freq[s[j]];
            while (freq[s[j]] > 1) {
                --freq[s[i]];
                ++i;
            }
            maxPrefix = max(maxPrefix, j - i + 1);
        }
        return maxPrefix;
    }
};
