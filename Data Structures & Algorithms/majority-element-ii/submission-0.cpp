class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> results;

        for ( int num : nums) {
            ++mp[num];
        }

        for (const auto &p : mp) {
            if (p.second > nums.size() / 3) {
                results.push_back(p.first);
            }
        }

        return results;
    }
};