class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for (int i = 0; i < row.size(); i ++) {
            for (int j = 0; j < col.size(); j++) {
                char c = board[i][j];
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (c == '.') {
                    continue;
                }
                if (row[i].count(c)) {
                    return false;
                }
                else if (col[j].count(c)) {
                    return false;
                }
                else if (box[boxIndex].count(c)) {
                    return false;
                }
                else {
                    row[i].insert(c);
                    col[j].insert(c);
                    box[boxIndex].insert(c);
                }
            }
        }
        return true;
    }
};
