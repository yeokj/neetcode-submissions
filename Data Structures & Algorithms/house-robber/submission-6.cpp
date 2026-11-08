class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int robOne = nums[0], robTwo = max(nums[1], nums[0]); 
        int n = nums.size();

        for (int i = 2; i < n; ++i) {
            int maxRob = max(robTwo, robOne + nums[i]);
            robOne = robTwo;
            robTwo = maxRob;
        }
        return robTwo;
    }
};
