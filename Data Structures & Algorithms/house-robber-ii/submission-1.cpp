class Solution {
public:
    int slice(vector<int> &nums, int k, int n) {
        int robOne = nums[k], robTwo = max(nums[k], nums[k + 1]);

        for (int i = k + 2; i <= n; ++i) {
            int temp = max(robTwo, robOne + nums[i]);
            robOne = robTwo;
            robTwo = temp;
        }
        return robTwo;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();
        int lootA = slice(nums, 0, n - 2), lootB = slice(nums, 1, n - 1);
        
        return max(lootA, lootB);
    }
};
