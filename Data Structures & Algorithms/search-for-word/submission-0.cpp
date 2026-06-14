class Solution {
public:
    bool backtrack(vector<vector<char>> &board, string &word, int j, int k, int i) {
        if (i == word.length()) return true;
        if (j < 0 || j >= board.size()) return false;
        if (k < 0 || k >= board[0].size()) return false;
        if (board[j][k] != word[i]) return false;

        char temp = board[j][k];
        board[j][k] = '#';

        if (backtrack(board, word, j + 1, k, i + 1)) return true;
        if (backtrack(board, word, j - 1, k, i + 1)) return true;
        if (backtrack(board, word, j, k + 1, i + 1)) return true;
        if (backtrack(board, word, j, k - 1, i + 1)) return true;

        board[j][k] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;

        int m = board.size(), n = board[0].size(), i = 0;

        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (board[j][k] == word[i]) {
                    if (backtrack(board, word, j, k, i)) return true;
                }
            }
        }
        return false;
    }
};
