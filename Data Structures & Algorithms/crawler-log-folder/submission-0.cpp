class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;

        for (string log : logs) {
            if (log == "../") {
                if (result > 0) --result;
            }
            else if (log != "./") ++result;
        }
        return result;
    }
};