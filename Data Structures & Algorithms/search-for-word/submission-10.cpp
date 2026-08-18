class Solution {
public:

    bool solve(vector<vector<char>>& board,string word,int i,int n,vector<vector<int>>& visited,int row,int col){
        if(i==n ){
            return true;
        }
        if (row < 0 || row >= board.size() ||col < 0 || col >= board[0].size()) {
            return false;
        }
        if(visited[row][col]){
            return false;
        }
        if(word[i]!=board[row][col]){
            return false;
        }
        visited[row][col]=1;
        bool top=solve(board,word,i+1,n,visited,row-1,col);
        bool bottom=solve(board,word,i+1,n,visited,row+1,col);
        bool left=solve(board,word,i+1,n,visited,row,col-1);
        bool right=solve(board,word,i+1,n,visited,row,col+1);
        visited[row][col]=0;

        return top||bottom || left || right;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size()));

        int i=0;
        int n=word.size();
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){

                if(solve(board,word,i,n,visited,row,col)){
                    return true;
                }
            }
        }
        return false;

    }
};
