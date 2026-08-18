class Solution {
public:

    void bsf(vector<vector<int>>& grid,int row,int col,int &area,vector< vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=true;
        while(!q.empty()){
            pair<int,int> top=q.front();
            q.pop();
            int tempRow=top.first;
            int tempCol=top.second;
            //up
            if(tempRow-1 >= 0  && !visited[tempRow-1][tempCol] && grid[tempRow-1][tempCol] ==1 ){
                area++;
                visited[tempRow-1][tempCol]=true;
                q.push({tempRow-1,tempCol});

            }
            //down
            if(tempRow+1 < grid.size() && !visited[tempRow+1][tempCol] && grid[tempRow+1][tempCol] ==1){
                area++;
                visited[tempRow+1][tempCol]=true;
                q.push({tempRow+1,tempCol});
            }
            //left

            if(tempCol-1 >=0 && !visited[tempRow][tempCol-1] && grid[tempRow][tempCol-1] ==1){
                area++;
                visited[tempRow][tempCol-1]=true;
                q.push({tempRow,tempCol-1});
            }
            //right
            if(tempCol+1 < grid[0].size() && !visited[tempRow][tempCol+1] && grid[tempRow][tempCol+1] ==1){
                area++;
                visited[tempRow][tempCol+1]=true;
                q.push({tempRow,tempCol+1});
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        vector< vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==1 && !visited[row][col]){
                    int area=1;
                    bsf(grid,row,col,area,visited);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
