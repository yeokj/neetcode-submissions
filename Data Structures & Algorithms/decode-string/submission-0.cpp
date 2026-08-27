class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string current = "";
        int k = 0;

        for(char c : s) {
            if (c == '[') {
                st.push({current, k});
                current = "";
                k = 0;
            }
            if (isdigit(c)) {
                int digit = c - '0';
                k = (k * 10) + digit;
            }
            if (isalpha(c)) {
                current += c;
            }
            if (c == ']') {
                string a = st.top().first;
                int n = st.top().second;
                string temp = current;
                for (int i = n; i > 0; --i) {
                    a += temp;
                }
                current = a;
                st.pop();
            }
        }
        return current;
    }
};