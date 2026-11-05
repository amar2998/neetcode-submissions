class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        bool rowZeros=false;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]==0){
                    matrix[0][col]=0;
                    if(row >0){
                        matrix[row][0]=0;
                    }
                    else{
                        rowZeros=true;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        if(rowZeros){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        
    }
};
