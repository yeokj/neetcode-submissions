class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = defaultdict(int)
        max_prefix, i = 0, 0

        for j in range(len(s)):
            mp[s[j]] += 1
            while mp[s[j]] > 1:
                mp[s[i]] -= 1
                i += 1
            max_prefix = max(max_prefix, j - i + 1)

        return max_prefix