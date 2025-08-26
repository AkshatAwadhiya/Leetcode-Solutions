class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxdiagonal = 0;
        int maxarea = 0;
        
        for (auto & rect : dimensions) {
            int length = rect[0];
            int width = rect[1];            
            int diagonalsquare = length * length + width * width;
            int area = length * width;
            
            if (diagonalsquare > maxdiagonal) {
                maxdiagonal = diagonalsquare;
                maxarea = area;
            }
            else if (diagonalsquare == maxdiagonal && area > maxarea) {
                maxarea = area;
            }
        }
        
        return maxarea;
    }
};