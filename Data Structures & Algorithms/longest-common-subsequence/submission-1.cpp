class Solution {
public:

    int solve(vector<vector<int>>& dp,string& str1,string& str2,int i,int j){
        if(i>=str1.length()){
            return 0;
        }
        if(j>=str2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(str1[i]==str2[j]){
            ans=1+solve(dp,str1,str2,i+1,j+1);
        }
        else{
            ans=max(solve(dp,str1,str2,i+1,j),solve(dp,str1,str2,i,j+1));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(dp,text1,text2,0,0);
    }
};
