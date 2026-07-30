class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        unordered_map<string, vector<string>> mp;
        for (const auto &str :strs) {
            int v[26] = {0};
            for (char c : str) {
                ++v[c - 'a'];
            }
            string key = "";
            for (int i : v) {
                key += to_string(i) + "#";
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> results;
        results.reserve(mp.size());
        for (const auto& p : mp) results.push_back(p.second);
        return results;
    }
};
