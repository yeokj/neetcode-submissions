class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size(), result = 0;;
        int profit1 = max(nums[0], nums[1]), profit2 = nums[0];

        for (int i = 2; i < n; ++i) {
            int curr = max(profit1, profit2 + nums[i]);
            profit2 = profit1;
            profit1 = curr;
        }

        result = max(profit1, profit2);

        return result;
    }
};
