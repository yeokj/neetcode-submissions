class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;

        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) ++fresh;
            }
        }

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int rottWave = q.size();
            bool isRotten = false;
            for (int i = 0; i < rottWave; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                int rotten = grid[row][col];
                q.pop();

                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = rotten;
                    q.push({row - 1, col});
                    --fresh;
                    isRotten = true;
                }
                if (row + 1 < m && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = rotten;
                    q.push({row + 1, col});
                    --fresh;
                    isRotten = true;
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = rotten;
                    q.push({row, col - 1});
                    --fresh;
                    isRotten = true;
                }
                if (col + 1 < n && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = rotten;
                    q.push({row, col + 1});
                    --fresh;
                    isRotten = true;
                }
            }
            if (isRotten) ++minutes;
        }
        if (fresh <= 0) return minutes;

        return -1;
    }
};
