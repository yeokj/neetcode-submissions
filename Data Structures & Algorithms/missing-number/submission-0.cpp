class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0, m = nums.back(), n = nums.size();

        for (int i = 0; i <= n; ++i) {
            missing ^= i;
        }

        for (const auto &num : nums) {
            missing ^= num;
        }
        return missing;
    }
};
