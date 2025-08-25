class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;        
        int row = 0, col = 0;
        bool goingUp = true;        
        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);
            
            if (goingUp) {
                if (col == n - 1) {
                    row++;
                    goingUp = false;
                } else if (row == 0) {
                    col++;
                    goingUp = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                    goingUp = true;
                } else if (col == 0) {
                    row++;
                    goingUp = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};