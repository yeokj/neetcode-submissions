class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (const auto &num : nums) {
            ++mp[num];
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &p : mp) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;
        result.reserve(k);
        for (int i = nums.size(); i >= 1; i--) {
            for (const auto & num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
