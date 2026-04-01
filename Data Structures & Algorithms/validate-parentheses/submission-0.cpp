class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {{')','('}, {'}','{'},{']','['}};
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (brackets.find(s[i]) == brackets.end()) {
                stack.push(s[i]);
            }
            else {
                if (stack.empty()) {
                    return false;
                }
                if (stack.top() != brackets[s[i]]) {
                    return false;
                }
                else {
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};
