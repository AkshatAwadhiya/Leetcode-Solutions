class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();        
        int diagonalSum = 0;
        for (int i = 0; i < n; i++) {
            diagonalSum += fruits[i][i];
        }        
        vector<vector<int>> dp2(n, vector<int>(n, -1));        
        function<int(int, int)> solve2 = [&](int i, int j) -> int {
            if (i == n-1 && j == n-1) {
                return 0;
            }
            
            if (i >= n || j < 0 || j >= n) {
                return -1e9;
            }            
            if (dp2[i][j] != -1) {
                return dp2[i][j];
            }            
            int result = -1e9;            
            for (int dj = -1; dj <= 1; dj++) {
                int ni = i + 1, nj = j + dj;
                int subResult = solve2(ni, nj);
                if (subResult > -1e8) {
                    result = max(result, subResult);
                }
            }            
            if (i != j || (i == n-1 && j == n-1)) {
                if (!(i == n-1 && j == n-1)) {
                    result += fruits[i][j];
                }
            }            
            return dp2[i][j] = result;
        };        
        vector<vector<int>> dp3(n, vector<int>(n, -1));
        function<int(int, int)> solve3 = [&](int i, int j) -> int {
            if (i == n-1 && j == n-1) {
                return 0;
            }            
            if (i < 0 || i >= n || j >= n) {
                return -1e9;
            }            
            if (dp3[i][j] != -1) {
                return dp3[i][j];
            }            
            int result = -1e9;            
            for (int di = -1; di <= 1; di++) {
                int ni = i + di, nj = j + 1;
                int subResult = solve3(ni, nj);
                if (subResult > -1e8) {
                    result = max(result, subResult);
                }
            }            
            if (i != j || (i == n-1 && j == n-1)) {
                if (!(i == n-1 && j == n-1)) {
                    result += fruits[i][j];
                }
            }            
            return dp3[i][j] = result;
        };        
        int child2Max = solve2(0, n-1);
        int child3Max = solve3(n-1, 0);        
        return diagonalSum + child2Max + child3Max;
    }
};