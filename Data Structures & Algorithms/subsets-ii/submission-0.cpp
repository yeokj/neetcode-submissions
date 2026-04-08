class Solution {
public:
    vector<vector<int>> result;
    vector<int> v;

    void backtrack(vector<int> &nums, int i) {
        if (i == nums.size()) {
            result.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        backtrack(nums, i + 1);
        v.pop_back();

        int next = i + 1;
        while (next < nums.size() && nums[next] == nums[i]) {
            ++next;
        }
        backtrack(nums, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);

        return result;
    }
};
