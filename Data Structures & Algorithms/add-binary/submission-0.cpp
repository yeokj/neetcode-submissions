class Solution {
public:
    string addBinary(string a, string b) {
        int bitA;
        int bitB;
        int sum;
        int carry = 0;
        char digit;
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry != 0) {
            bitA = i >= 0 ? a[i] - '0' : 0;
            bitB = j >= 0 ? b[j] - '0' : 0;
            sum = bitA + bitB + carry;
            carry = sum / 2;
            digit = '0' + (sum % 2);
            result += digit;
            --i;
            --j;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};