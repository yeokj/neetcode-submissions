class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {};
        }
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (!mp.count(target - nums[i])) {
                mp[nums[i]] = i;
            }
            else {
                return vector<int>{mp[target - nums[i]], i};
            }
        }
        return {};
    }
};
