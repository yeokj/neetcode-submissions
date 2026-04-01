class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> target;
        unordered_map<char, int> window;
        int i = 0;
        for (char c : s1) target[c]++;

        for (int j = 0; j < s2.length(); ++j) {
            ++window[s2[j]];
            if ((j - i + 1) > s1.length()) {
                --window[s2[i]];
                if (window[s2[i]] == 0) {
                    window.erase(s2[i]);
                }
                ++i;
            }
            if (window == target) {
                return true;
            }
        }
        return false;
    }
};
