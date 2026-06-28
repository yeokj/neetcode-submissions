class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();
        int profitOne = nums[0], profitTwo = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            int temp = max(profitTwo, profitOne + nums[i]);
            profitOne = profitTwo;
            profitTwo = temp;
        }
        return profitTwo;
    }
};
