class Solution {
public:
    vector<vector<int>> result;
    vector<int> v;

    void backtrack(int index, vector<int> &nums) {
        if (index == nums.size()) {
            result.push_back(v);
            return;
        }

        v.push_back(nums[index]);
        backtrack(index + 1, nums);
        v.pop_back();

        backtrack(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);

        return result;
    }
};
