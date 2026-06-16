class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    void backtrack(vector<string> &v, int n, int row) {
        if (row == n) {
            result.push_back(v);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }
            v[row][col] = 'Q';
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            backtrack(v, n, row + 1);
            v[row][col] = '.';
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        backtrack(v, n, 0);

        return result;
    }
};
