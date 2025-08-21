class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> heights(n, 0);
        int totalCount = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            totalCount += countSubmatricesInHistogram(heights);
        }
        
        return totalCount;
    }
    
private:
    int countSubmatricesInHistogram(vector<int>& heights) {
        int n = heights.size();
        int count = 0;
        
        for (int j = 0; j < n; j++) {
            int minHeight = heights[j];
            
            for (int k = j; k >= 0 && heights[k] > 0; k--) {
                minHeight = min(minHeight, heights[k]);
                
                count += minHeight;
            }
        }
        
        return count;
    }
};