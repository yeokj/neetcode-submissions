class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> results(n + 1, 0);

        for (auto& t : trust) {
            --results[t[0]]; 
            ++results[t[1]];
        }

        for (int i = 1; i <= n; i++) {
            if (results[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};