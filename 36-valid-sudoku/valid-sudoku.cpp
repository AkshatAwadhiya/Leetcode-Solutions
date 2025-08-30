class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rows[i].count(ch) || cols[j].count(ch) || boxes[boxIndex].count(ch))
                    return false;

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[boxIndex].insert(ch);
            }
        }

        return true;
    }
};
