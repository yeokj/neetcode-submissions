class Solution {
public:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c, int prevWeight) {
        if (r < 0 || r >= heights.size()) return;
        if (c < 0 || c >= heights[0].size()) return;
        if (visited[r][c] == true) return;
        if (heights[r][c] < prevWeight) return;

        visited[r][c] = true;

        dfs(heights, visited, r - 1, c, heights[r][c]);
        dfs(heights, visited, r + 1, c, heights[r][c]);
        dfs(heights, visited, r, c - 1, heights[r][c]);
        dfs(heights, visited, r, c + 1, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            dfs(heights, pacific, r, 0, heights[r][0]);
            dfs(heights, atlantic, r, n - 1, heights[r][n - 1]);
        }
        for (int c = 0; c < n; ++c) {
            dfs(heights, pacific, 0, c, heights[0][c]);
            dfs(heights, atlantic, m - 1, c, heights[m - 1][c]);
        }

        vector<vector<int>> results;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (atlantic[r][c] && pacific[r][c]) {
                    results.push_back({r, c});
                }
            }
        }

        return results;
    }
};
