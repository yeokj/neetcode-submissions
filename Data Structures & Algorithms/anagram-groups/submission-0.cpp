class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1) {
            return {{strs[0]}};
        }
        unordered_map<string, vector<string>> freq;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            freq[temp].push_back(strs[i]);
        }
        vector<vector<string>> results;

        for (const auto& pair : freq) {
            results.push_back(pair.second);
        }

        return results;
    }
};
