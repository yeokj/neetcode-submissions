class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], curr = 0, n = nums.size();;

        for (int i = 0; i < n; ++i) {
            curr = max(nums[i], nums[i] + curr);
            result = max(result, curr);
        }

        return result;
    }
};
