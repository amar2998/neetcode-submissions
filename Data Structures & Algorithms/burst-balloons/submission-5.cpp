class Solution {
public:

    int dfs(vector<int>& newNums,int left,int right,vector<vector<int>>& dp){
        if(left > right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        dp[left][right]=0;
        int maxPoints=0; 
        for(int k=left;k<=right;k++){
            int points=newNums[left-1]*newNums[k]*newNums[right+1];
            points+=dfs(newNums,left,k-1,dp)+dfs(newNums,k+1,right,dp);
            maxPoints=max(maxPoints,points);
        }
        return dp[left][right]=maxPoints;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int m=n+2;
        vector<int> newNums(m,1);
        for(int i=0;i<n;i++){
            newNums[i+1]=nums[i];
        }

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return dfs(newNums,1,newNums.size()-2,dp);
    }
};
