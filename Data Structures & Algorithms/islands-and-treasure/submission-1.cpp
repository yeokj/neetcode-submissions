class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) q.push({r, c});
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int treasure = grid[row][col];

            q.pop();

            if (row - 1 >= 0 && grid[row - 1][col] == INT_MAX) {
                grid[row - 1][col] = treasure + 1;
                q.push({row - 1, col});
            }
            if (row + 1 < m && grid[row + 1][col] == INT_MAX) {
                grid[row + 1][col] = treasure + 1;
                q.push({row + 1, col});
            }
            if (col - 1 >= 0 && grid[row][col - 1] == INT_MAX) {
                grid[row][col - 1] = treasure + 1;
                q.push({row, col - 1});
            }
            if (col + 1 < n && grid[row][col + 1] == INT_MAX) {
                grid[row][col + 1] = treasure + 1;
                q.push({row, col + 1});
            }
        }
    }
};
