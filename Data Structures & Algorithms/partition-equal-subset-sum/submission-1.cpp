class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (const int num : nums) total += num;
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (const int num : nums) {
            if (num > target) return false;
            for (int t = target; t >= num; --t) {
                dp[t] = dp[t] || dp[t - num];
            }
            if (dp[target]) return true;
        }
        return dp[target];
    }
};
