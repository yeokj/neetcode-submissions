class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = (row * col) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / col;
            int c = mid % col;
            int val = matrix[r][c];

            if (val < target) {
                low = mid + 1;
            }
            else if (val > target) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
