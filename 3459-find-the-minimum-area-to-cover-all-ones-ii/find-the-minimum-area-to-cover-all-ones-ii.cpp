class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();        
        int result = INT_MAX;        
        for (int i = 1; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                int area1 = getRectangleArea(grid, 0, 0, i - 1, n - 1);
                int area2 = getRectangleArea(grid, i, 0, j - 1, n - 1);
                int area3 = getRectangleArea(grid, j, 0, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }        
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int area1 = getRectangleArea(grid, 0, 0, m - 1, i - 1);
                int area2 = getRectangleArea(grid, 0, i, m - 1, j - 1);
                int area3 = getRectangleArea(grid, 0, j, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int area1 = getRectangleArea(grid, 0, 0, i - 1, j - 1);
                int area2 = getRectangleArea(grid, 0, j, i - 1, n - 1);
                int area3 = getRectangleArea(grid, i, 0, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int area1 = getRectangleArea(grid, 0, 0, i - 1, n - 1);
                int area2 = getRectangleArea(grid, i, 0, m - 1, j - 1);
                int area3 = getRectangleArea(grid, i, j, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int area1 = getRectangleArea(grid, 0, 0, j - 1, i - 1);
                int area2 = getRectangleArea(grid, j, 0, m - 1, i - 1);
                int area3 = getRectangleArea(grid, 0, i, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int area1 = getRectangleArea(grid, 0, 0, m - 1, i - 1);
                int area2 = getRectangleArea(grid, 0, i, j - 1, n - 1);
                int area3 = getRectangleArea(grid, j, i, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        return result;
    }
    
private:
    int getRectangleArea(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int minRow = r2 + 1, maxRow = r1 - 1;
        int minCol = c2 + 1, maxCol = c1 - 1;
        
        bool hasOne = false;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1) {
                    hasOne = true;
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        
        if (!hasOne) return 0;
        
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};