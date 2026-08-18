class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int row,int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            pair<int,int> data=q.front();
            q.pop();
            int tempRow=data.first;
            int tempCol=data.second;
            //up
            if(tempRow-1 >=0 && !visited[tempRow-1][tempCol] && grid[tempRow-1][tempCol]=='1'){
                q.push({tempRow-1,tempCol});
                visited[tempRow-1][tempCol]=true;
            }

            //down
            if(tempRow +1 < grid.size() && !visited[tempRow+1][tempCol] && grid[tempRow+1]
            [tempCol]=='1'){
                q.push({tempRow+1,tempCol});
                visited[tempRow+1][tempCol]=true;
            }

            //left
            if(tempCol -1 >=0 &&  !visited[tempRow][tempCol-1] && grid[tempRow]
            [tempCol-1]=='1'){
                q.push({tempRow,tempCol-1});
                visited[tempRow][tempCol-1]=true;
            }

            //right

            if(tempCol +1 < grid[0].size() && !visited[tempRow][tempCol+1] && grid[tempRow]
            [tempCol+1]=='1'){
                q.push({tempRow,tempCol+1});
                visited[tempRow][tempCol+1]=true;
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(grid, visited, i, j);

                }
            }
        }
        return count;
        
    }
};
