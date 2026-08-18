class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //up
            if(row-1 >= 0 && col < n && col >=0 && grid[row-1][col] == INT_MAX){
                grid[row-1][col]=grid[row][col] + 1;
                q.push({row-1,col});
            }
            //down
            if(row+1 < m && col < n && col >=0 && grid[row+1][col] == INT_MAX){
                grid[row+1][col]=grid[row][col]+1;
                q.push({row+1,col});
            }
            //left
            if(row < m && row >=0 && col-1 >=0 && grid[row][col-1] == INT_MAX){
                grid[row][col-1]=grid[row][col]+1;
                q.push({row,col-1});
            }
            //right
            if(row <m && row >=0 && col+1 <n && grid[row][col+1] ==INT_MAX){
                grid[row][col+1]=grid[row][col]+1;
                q.push({row,col+1});
            }
        }
    }
};