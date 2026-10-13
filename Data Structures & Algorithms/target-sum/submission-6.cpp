class Solution {
public:
    int DSF(vector<int>& nums,int target,int index,int sum,vector<vector<int>>& dp,int offset){
        if(index>=nums.size()){
            return sum==target?1:0;
        }
        if(dp[index][sum+offset]!=-1){
            return dp[index][sum+offset];
        }
        int addsum=DSF(nums,target,index+1,sum+nums[index],dp,offset);
        int subSum=DSF(nums,target,index+1,sum-nums[index],dp,offset);

        return dp[index][sum+offset]=addsum+subSum;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        if (target > total || target < -total) {
            return 0;
        }

        int offset = total;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(2 * total + 1, -1)
        );
        return DSF(nums,target,0,0,dp,offset);
        
    }
};
