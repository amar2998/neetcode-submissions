class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean,vector<vector<int>>& heights) {
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            ocean[r][c]=true;
            //up
            if(r-1 >= 0 && r-1 < heights.size() && c >= 0 && c < heights[0].size() &&
             !ocean[r-1][c]  &&  heights[r-1][c] >= heights[r][c]){
                q.push({r-1,c});
            }
            //down
            if(r+1 >= 0 && r+1 < heights.size() && c >= 0 && c < heights[0].size() &&
             !ocean[r+1][c]  &&  heights[r+1][c] >= heights[r][c]){
                q.push({r+1,c});
            }
            //left
            if(r >= 0 && r < heights.size() && c-1 >= 0 && c-1 < heights[0].size() &&
             !ocean[r][c-1]  &&  heights[r][c-1] >= heights[r][c]){
                q.push({r,c-1});
            }
            //right
            if(r >= 0 && r < heights.size() && c+1 >= 0 && c+1 < heights[0].size() &&
             !ocean[r][c+1]  &&  heights[r][c+1] >= heights[r][c]){
                q.push({r,c+1});
            }
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS=heights.size();
        int COLS=heights[0].size();
        vector<vector<bool>> atcOcean(ROWS,vector<bool>(COLS,false));
        vector<vector<bool>> pcfOcean(ROWS,vector<bool>(COLS,false));

        queue<pair<int,int>> atlQueue;
        queue<pair<int,int>> pcfQueue;

        for(int r=0;r<ROWS;r++){
            pcfQueue.push({r,0});
            atlQueue.push({r,COLS-1});
        }
        for(int c=0;c<COLS;c++){
            pcfQueue.push({0,c});
            atlQueue.push({ROWS-1,c});
        }

        bfs(pcfQueue, pcfOcean, heights);
        bfs(atlQueue, atcOcean, heights);
        vector<vector<int>> ans;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(pcfOcean[i][j] && atcOcean[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;


    }
};
