class Solution {
public:
    const unordered_map<char, string> keypad = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> result;

    void backtrack(const unordered_map<char, string> &keypad, string &digits, string &s, int start) {
        if (start == digits.length()) {
            result.push_back(s);
            return;
        }

        string letters = keypad.at(digits[start]);
        for (int i = 0; i < letters.length(); ++i) {
            s.push_back(letters[i]);
            backtrack(keypad, digits, s, start + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string s = "";
        backtrack(keypad, digits, s, 0);

        return result;
    }
};
