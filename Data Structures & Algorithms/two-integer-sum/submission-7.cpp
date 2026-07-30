class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                return vector<int>{it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
