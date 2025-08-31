class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(board, row, col, digit)) {
                            board[row][col] = digit;
                            
                            if (solve(board)) {
                                return true;
                            }
                            
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == digit) {
                return false;
            }
        }
        
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == digit) {
                return false;
            }
        }
        
        int boxStartRow = (row / 3) * 3;
        int boxStartCol = (col / 3) * 3;
        for (int r = boxStartRow; r < boxStartRow + 3; r++) {
            for (int c = boxStartCol; c < boxStartCol + 3; c++) {
                if (board[r][c] == digit) {
                    return false;
                }
            }
        }
        
        return true;
    }
};