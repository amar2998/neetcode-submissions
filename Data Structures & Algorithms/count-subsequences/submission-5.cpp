class Solution {
public:

    int DFS(int i,int j,string s,string t,vector<vector<int>> & dp){
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];

        }

        if(s[i]==t[j]){
            dp[i][j]=DFS(i+1,j+1,s,t,dp)+DFS(i+1,j,s,t,dp);
        }
        else{
            dp[i][j]=DFS(i+1,j,s,t,dp);
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int sLength=s.size();
        int tLength=t.size();
        if(tLength > sLength){
            return 0;
        }
        vector<vector<int>> dp(sLength,vector<int>(tLength,-1));

        int i=0;
        int j=0;
        return DFS(i,j,s,t,dp);

        
    }
};
