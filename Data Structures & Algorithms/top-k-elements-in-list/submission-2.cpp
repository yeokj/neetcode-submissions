class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (const auto &num : nums) {
            ++freq[num];
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto &pair : freq) {
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> result;

        for (int i = nums.size(); i >= 1; i--) {
            for (const auto & num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
            if (result.size() == k) {
                break;
            }
        }
        return result;
    }
};
