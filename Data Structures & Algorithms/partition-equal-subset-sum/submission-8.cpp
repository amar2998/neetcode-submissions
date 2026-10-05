class Solution {
public:
    bool solve(vector<int>&nums,int target,int index,vector<vector<int>>& dp){
        if(target ==0){
            return true;
        }
        if(target < 0){
            return false;
        }
        if(index >= nums.size()){
            return false;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool include=solve(nums,target-nums[index],index+1,dp);
        bool exclude=solve(nums,target,index+1,dp);
        return dp[index][target]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0 ){
            return false;
        }
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums,target,0,dp);
    }
};
