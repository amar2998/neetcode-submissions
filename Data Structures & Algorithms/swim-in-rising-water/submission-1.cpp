class Solution {
public:

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
             int row, int col, int n, int m, int water) {

        if (row < 0 || row >= n || col < 0 || col >= m) {
            return false;
        }

        if (visited[row][col]) {
            return false;
        }

        if (grid[row][col] > water) {
            return false;
        }

        if (row == n - 1 && col == m - 1) {
            return true;
        }

        visited[row][col] = true;

        if (dfs(grid, visited, row + 1, col, n, m, water)) {
            return true;
        }

        if (dfs(grid, visited, row - 1, col, n, m, water)) {
            return true;
        }

        if (dfs(grid, visited, row, col + 1, n, m, water)) {
            return true;
        }

        if (dfs(grid, visited, row, col - 1, n, m, water)) {
            return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int low = grid[0][0];
        int high = n * m - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            vector<vector<bool>> visited(
                n, vector<bool>(m, false)
            );

            if (dfs(grid, visited, 0, 0, n, m, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};