class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >=0; --j) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int sum = prod + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        int i = 0, k = result.size();
        while (i < k && result[i] == 0) ++i;

        string resultString = "";
        for (int j = i; j < k; ++j) {
            resultString += result[j] + '0';
        }

        if (resultString.empty()) return "0";
        return resultString;
    }
};
