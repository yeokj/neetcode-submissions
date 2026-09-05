class Solution {
void dfs(vector<vector<int>> &image, int r, int c, int val, int color) {
        if (r < 0 || r >= image.size()) return;
        if (c < 0 || c >= image[0].size()) return;
        if (image[r][c] != val) return;
        if (image[r][c] == color) return;

        image[r][c] = color;

        dfs(image, r + 1, c, val, color);
        dfs(image, r - 1, c, val, color);
        dfs(image, r, c + 1, val, color);
        dfs(image, r, c - 1, val, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        if (val == color) return image;
        dfs(image, sr, sc, val, color);
        return image;
    }
};