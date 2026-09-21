class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,false));
        int resInd=0;
        int resLen=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && ((j-i <=2 || dp[i+1][j-1]))){
                    dp[i][j]=true;
                    ans++;  
                }
            }
        }
        return ans;
    }
};
