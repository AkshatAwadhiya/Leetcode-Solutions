class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int waterTrapped = 0;
        int maxHeight = 0;
        vector<int> directions = {-1, 0, 1, 0, -1};        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int height = curr[0];
            int row = curr[1];
            int col = curr[2];            
            maxHeight = max(maxHeight, height);            
            for (int d = 0; d < 4; d++) {
                int newRow = row + directions[d];
                int newCol = col + directions[d + 1];                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && !visited[newRow][newCol]) {
                    
                    visited[newRow][newCol] = true;                    
                    if (maxHeight > heightMap[newRow][newCol]) {
                        waterTrapped += maxHeight - heightMap[newRow][newCol];
                    }                    
                    pq.push({heightMap[newRow][newCol], newRow, newCol});
                }
            }
        }
        
        return waterTrapped;
    }
};