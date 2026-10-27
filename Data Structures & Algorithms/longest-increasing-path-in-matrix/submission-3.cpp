
class Solution {
public:
    int DFS(vector<vector<int>>& matrix, int row, int col,
            vector<vector<int>>& LIP) {

        if(LIP[row][col]!=0){
            return LIP[row][col];
        }
         int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int maxINcreasingPath=1;

        //up
        if(row >0 && matrix[row-1][col] > matrix[row][col]){
            maxINcreasingPath=max(maxINcreasingPath,1+DFS(matrix,row-1,col,LIP));
        }
        //down
        if(row +1< rowSize && matrix[row+1][col] > matrix[row][col]){
            maxINcreasingPath=max(maxINcreasingPath,1+DFS(matrix,row+1,col,LIP));
        }
        if(col >0 && matrix[row][col-1] > matrix[row][col]){
            maxINcreasingPath=max(maxINcreasingPath,1+DFS(matrix,row,col-1,LIP));
        }
        if(col +1< colSize && matrix[row][col+1] > matrix[row][col]){
            maxINcreasingPath=max(maxINcreasingPath,1+DFS(matrix,row,col+1,LIP));
        }
        return LIP[row][col]=maxINcreasingPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();

        if (rowSize == 0) {
            return 0;
        }

        int colSize = matrix[0].size();

        vector<vector<int>> LIP(rowSize, vector<int>(colSize, 0));

        int maxEle = 0;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                maxEle = max(maxEle, DFS(matrix, i, j, LIP));
            }
        }

        return maxEle;
    }
};
