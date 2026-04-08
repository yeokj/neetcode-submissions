class Solution {
public:
    vector<vector<int>> result;
    vector<int> v;
    int currSum = 0;

    void backtrack(vector<int> &nums, int target, int i) {
        if (currSum == target) {
            result.push_back(v);
            return;
        }
        if (currSum > target || i >= nums.size())
            return;

        v.push_back(nums[i]);
        currSum += nums[i];
        backtrack(nums, target, i);

        v.pop_back();
        currSum -= nums[i];

        backtrack(nums, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);

        return result;
    }
};
