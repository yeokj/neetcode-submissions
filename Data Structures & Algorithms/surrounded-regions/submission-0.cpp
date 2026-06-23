class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c) {
        if (r < 0 || r >= board.size()) return;
        if (c < 0 || c >= board[0].size()) return;
        if (visited[r][c] == true) return;
        if (board[r][c] == 'X') return;

        visited[r][c] = true;

        dfs(board, visited, r - 1, c);
        dfs(board, visited, r + 1, c);
        dfs(board, visited, r, c - 1);
        dfs(board, visited, r, c + 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            dfs(board, visited, r, 0);
            dfs(board, visited, r, n - 1);
        }
        for (int c = 0; c < n; ++c) {
            dfs(board, visited, 0, c);
            dfs(board, visited, m - 1, c);
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!visited[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
