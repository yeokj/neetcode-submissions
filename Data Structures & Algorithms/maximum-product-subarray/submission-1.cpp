class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0], currMax = nums[0];
        int n = nums.size(), result = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) swap(currMax, currMin);
            currMin = min(nums[i], currMin * nums[i]);
            currMax = max(nums[i], currMax * nums[i]);
            result = max(result, currMax);
        }
        return result;
    }
};
