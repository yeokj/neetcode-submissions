class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for (char c : t) {
            ++target[c];
        }
        unordered_map<char, int> window;
        int minLeft = 0;
        int minLen = INT_MAX;
        int form = 0;
        int i = 0;

        for (int j = 0; j < s.length(); ++j) {
            ++window[s[j]];
            if (target.count(s[j]) && window[s[j]] == target[s[j]]) {
                ++form;
            }
            while (form == target.size()) {
                if (j - i + 1 < minLen) {
                    minLeft = i;
                    minLen = j - i + 1;
                }
                if (target.count(s[i])) {
                    --window[s[i]];
                    if (window[s[i]] < target[s[i]]) {
                        --form;
                    }
                }
                ++i;
            }
        }
        if (minLen == INT_MAX) {
            return "";
        } 
        return s.substr(minLeft, minLen);
    }
};
