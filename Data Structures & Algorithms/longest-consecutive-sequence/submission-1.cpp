class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (const auto &num : nums) {
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int streak = 1;
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
