class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxReach = 0, currentEnd = 0;
        int jump = 0, n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            maxReach = max(maxReach, i + nums[i]);
            if (i == currentEnd) {
                ++jump;
                currentEnd = maxReach;
            }
        }
        return jump;
    }
};
