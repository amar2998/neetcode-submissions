class Solution {

public:
    int solve(vector<int>& nums,int index,int n,vector<int>&dp){
        if(index>=n-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int maxJump=nums[index];
        int minJump=INT_MAX;
        if(maxJump==0){
            return INT_MAX;
        }
        for(int i=1;i<=maxJump;i++){
            int jump=solve(nums,index+i,n,dp);
            if(jump!=INT_MAX){
                minJump=min(minJump,jump+1);
            }
        }
        dp[index]=minJump;
        return minJump;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,n,dp);
        
    }
};
