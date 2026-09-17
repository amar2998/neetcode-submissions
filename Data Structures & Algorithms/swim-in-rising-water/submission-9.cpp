class Solution {
public:

    bool DFS(vector<vector<int>>& grid,int water,int row,int col,int n,int m,vector<vector<bool>>& visited){
        if(row <0 || row>=n || col <0 || col>=m){
            return false;
        }
        if(grid[row][col]> water){
            return false;
        }
        if(visited[row][col]){
            return false;
        }
        if(row==n-1 && col==m-1){
            return true;
        }
        visited[row][col]=true;
        if(DFS(grid,water,row+1,col,n,m,visited)){
            return true;
        }
        if(DFS(grid,water,row-1,col,n,m,visited)){
            return true;
        }
        if(DFS(grid,water,row,col-1,n,m,visited)){
            return true;
        }
        if(DFS(grid,water,row,col+1,n,m,visited)){
            return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int low=grid[0][0];
        int high=n*m-1;
        // int result=0;
        while(low < high){
            int mid=low+(high-low)/2;
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            if(DFS(grid,mid,0,0,n,m,visited)){
                // result=mid;
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
