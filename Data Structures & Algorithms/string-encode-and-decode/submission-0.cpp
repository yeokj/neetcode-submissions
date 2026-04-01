class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (int i = 0; i < strs.size(); i++) {
            s += to_string(strs[i].length()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;

        while (i < s.length()) {
            int length = 0;
            while (isdigit(s[i])) {
                length = length * 10 + (s[i] - '0');
                i++;
            }
            i++;
            string word = s.substr(i, length);

            strs.push_back(word);

            i += length;
        }
        return strs;
    }
};
