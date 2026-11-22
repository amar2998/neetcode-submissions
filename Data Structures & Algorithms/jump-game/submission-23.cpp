class Solution {
public:

    bool solve(vector<int>& nums, int index, int n,vector<int>& dp) {

        if(index == n-1) {
            return true;
        }

        if(index >= n) {
            return false;
        }

        if(nums[index] == 0) {
            return false;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int maxJump = nums[index];

        bool result = false;

        for(int i = 1; i <= maxJump; i++) {

            bool ans = (index+i < n) && solve(nums, index+i, n,dp);

            result = result || ans;
            
        }

        return dp[index]=result;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);

        return solve(nums, 0, n,dp);
    }
};