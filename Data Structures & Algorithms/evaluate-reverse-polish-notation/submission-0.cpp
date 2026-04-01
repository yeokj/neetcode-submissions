class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        unordered_set<string> token {"+", "-", "*", "/"};

        for (const auto &toke : tokens) {
            if (token.count(toke)) {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (toke == "+") {
                    int result = b + a;
                    stack.push(result);
                }
                if (toke == "-") {
                    int result = b - a;
                    stack.push(result);
                }
                if (toke == "*") {
                    int result = b * a;
                    stack.push(result);
                }
                if (toke == "/") {
                    int result = b / a;
                    stack.push(result);
                }
            }
            else {
                stack.push(stoi(toke));
            }
        }
        return stack.top();
    }
};
