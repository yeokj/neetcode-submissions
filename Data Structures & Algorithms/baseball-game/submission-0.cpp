class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int result = 0;

        for (string op : operations) {
            if (op == "C") {
                s.pop();
            }
            else if (op == "D") {
                int product = s.top() * 2;
                s.push(product);
            }
            else if (op == "+") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                int total = num1 + num2;
                s.push(num1);
                s.push(num2);
                s.push(total);
            }
            else {
                s.push(stoi(op));
            } 
        }

        while (!s.empty()) {
            result += s.top();
            s.pop();
        }

        return result;
    }
};