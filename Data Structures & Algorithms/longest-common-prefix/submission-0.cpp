class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) {
            return "";
        }
        string base = strs[0];
        string prefix = "";
        bool match = true;

        for (int j = 0; j < base.length(); ++j) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].length() < j || strs[i][j] != base [j]) {
                    match = false;
                    break;
                }
            }
            if (match == false) {
                break;
            }
            prefix += base[j];
        }
        return prefix;
    }
};