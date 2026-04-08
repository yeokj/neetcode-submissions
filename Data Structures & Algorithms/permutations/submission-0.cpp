class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int> &nums, int i) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);

            swap(nums[j], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);

        return result;
    }
};
