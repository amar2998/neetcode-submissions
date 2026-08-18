class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        int r=row;int c=col;
        while(r<n && c< n){
            if(board[r][c]=='Q'){
                return false;
            }
            r++;
            c++;
        }
        r=row;
        c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
        r=row;
        c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r++;
            c--;
        }
        r=row;
        c=col;
        while(c<n && r>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            c++;
            r--;
        }
        return true;
    }

    void nQueen(vector<vector<string>>& ans,vector<string>& board,int row,int n){
        if(row==n){
            ans.push_back(board);
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                nQueen(ans,board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for(int i=0;i<n;i++){
            string data="";
            for(int j=0;j<n;j++){
                data.push_back('.');
            }
            board.push_back(data);
        }
        int row=0;
        nQueen(ans,board,row,n);
        return ans;
    }
};
