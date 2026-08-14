class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> v(26, 0);
        for (char c : s) {
            ++v[c - 'a'];
        }

        for (char c : t) {
            if (v[c - 'a'] == 0) return false;
            --v[c - 'a'];
        }
        return true;
    }
};
