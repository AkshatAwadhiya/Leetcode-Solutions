class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direindex = 0;

        int row = 0, col = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m * n; i++) {
            result.push_back(matrix[row][col]);
            visited[row][col] = true;

            int nextRow = row + directions[direindex][0];
            int nextCol = col + directions[direindex][1];

            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n ||
                visited[nextRow][nextCol]) {
                direindex = (direindex + 1) % 4;
                nextRow = row + directions[direindex][0];
                nextCol = col + directions[direindex][1];
            }

            row = nextRow;
            col = nextCol;
        }

        return result;
    }
};