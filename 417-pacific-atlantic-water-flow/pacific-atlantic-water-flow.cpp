class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);
        }
        
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j, m, n);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, 
             int row, int col, int m, int n) {
        reachable[row][col] = true;
        
        vector<int> directions = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int newRow = row + directions[d];
            int newCol = col + directions[d + 1];            
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) {
                continue;
            }
            
            if (reachable[newRow][newCol]) {
                continue;
            }
            

            if (heights[newRow][newCol] >= heights[row][col]) {
                dfs(heights, reachable, newRow, newCol, m, n);
            }
        }
    }
};