class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), i = 0;
        int currSum = 0, currLen = 0, result = INT_MAX;

        for (int j = 0; j < n; ++j) {
            currSum += nums[j];
            while (i <= j && currSum >= target) {
                currSum -= nums[i];
                result = min(result, (j - i) + 1);
                ++i;
            }
        }
        if (i == 0) return i;

        return result;
    }
};