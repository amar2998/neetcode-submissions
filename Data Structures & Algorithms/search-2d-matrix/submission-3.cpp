class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0;i<matrix.size();i++){
            int row=i;
            int leftCol=0;
            // int rightRow=i;
            int rightCol=matrix[i].size()-1;

            while(leftCol <= rightCol){
                int mid=leftCol+(rightCol-leftCol)/2;
                if(matrix[row][mid]==target){
                    return true;
                }
                else if(matrix[row][mid] < target){
                    leftCol=mid+1;
                }
                else{
                    rightCol=mid-1;
                }
            }
        }
        return false;
        
    }
};
