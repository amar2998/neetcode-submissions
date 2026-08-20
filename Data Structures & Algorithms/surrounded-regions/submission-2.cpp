class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0|| i==board.size() || j==board[0].size() || board[i][j]!='O'){
            return;
        }
        board[i][j]='T';
        //up
        dfs(board,i-1,j);
        //down
        dfs(board,i+1,j);
        //left
        dfs(board,i,j-1);
        //right
        dfs(board,i,j+1);

    }
    void solve(vector<vector<char>>& board) {
        // step 1

        for(int i=0;i<board.size();i++){
            for(int j=0;j< board[0].size();j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }

    }
};
