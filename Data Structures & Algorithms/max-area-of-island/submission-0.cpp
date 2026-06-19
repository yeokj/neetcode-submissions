class Solution {
public:
    void dfs(vector<vector<int>> &grid, int &area, int r, int c) {
        if (r < 0 || r >= grid.size()) return;
        if (c < 0 || c >= grid[0].size()) return;
        if (grid[r][c] == 0) return;
        if (grid[r][c] == 1) ++area;

        grid[r][c] = 0;

        dfs(grid, area, r - 1, c);
        dfs(grid, area, r + 1, c);
        dfs(grid, area, r, c - 1);
        dfs(grid, area, r, c + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int row = grid.size(), col = grid[0].size();
        int area = 0, maxArea = 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] == 1) {
                    dfs(grid, area, r, c);
                }
                maxArea = max(maxArea, area);
                area = 0;
            }
        }
        return maxArea;
    }
};
