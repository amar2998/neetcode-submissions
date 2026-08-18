class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool rottenMinutes = false;

            while (size--) {

                pair<int, int> top = q.front();
                q.pop();

                int row = top.first;
                int col = top.second;

                // up
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    fresh--;
                    rottenMinutes = true;
                }

                // down
                if (row + 1 < rowSize && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    fresh--;
                    rottenMinutes = true;
                }

                // left
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    fresh--;
                    rottenMinutes = true;
                }

                // right
                if (col + 1 < colSize && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    fresh--;
                    rottenMinutes = true;
                }
            }

            if (rottenMinutes) {
                time++;
            }
        }

        if (fresh > 0) {
            return -1;
        }

        return time;
    }
};