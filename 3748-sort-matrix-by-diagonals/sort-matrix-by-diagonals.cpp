class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();        
        for (int startRow = 0; startRow < n; startRow++) {
            processDiagonal(grid, startRow, 0, n, true);
        }        
        for (int startCol = 1; startCol < n; startCol++) {
            processDiagonal(grid, 0, startCol, n, false);
        }
        
        return grid;
    }
    
private:
    void processDiagonal(vector<vector<int>>& grid, int startRow, int startCol, int n, bool isBottomLeft) {
        vector<int> diagonal;
        vector<pair<int, int>> positions;        
        int row = startRow, col = startCol;
        while (row < n && col < n) {
            diagonal.push_back(grid[row][col]);
            positions.push_back({row, col});
            row++;
            col++;
        }
        
        if (isBottomLeft || (startRow == 0 && startCol == 0)) {
            sort(diagonal.begin(), diagonal.end(), greater<int>());
        } else {
            sort(diagonal.begin(), diagonal.end());
        }        
        for (int i = 0; i < diagonal.size(); i++) {
            grid[positions[i].first][positions[i].second] = diagonal[i];
        }
    }
};