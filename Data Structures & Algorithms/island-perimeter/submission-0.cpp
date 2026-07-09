class Solution {
public:
    void dfs(vector<vector<int>> &grid, int &result, int r, int c) {
        if (r < 0 || r >= grid.size()) {
            ++result;
            return;
        }
        if (c < 0 || c >= grid[0].size()) {
            ++result;
            return;
        }
        if (grid[r][c] == 0) {
            ++result;
            return;
        }
        if (grid[r][c] == -1) return;

        grid[r][c] = -1;

        dfs(grid, result, r - 1, c);
        dfs(grid, result, r + 1, c);
        dfs(grid, result, r, c - 1);
        dfs(grid, result, r, c + 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int result = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dfs(grid, result, r, c);
                }
            }
        }
        return result;
    }
};