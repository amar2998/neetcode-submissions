class Solution {
public:

    int robP(vector<int>& nums, int start, int end) {

        int size = end - start + 1;

        if (size == 1) {
            return nums[start];
        }

        vector<int> dp(size, -1);

        dp[0] = nums[start];

        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2, j = 2; i <= end; i++, j++) {

            dp[j] = max(
                dp[j - 1],
                dp[j - 2] + nums[i]
            );
        }

        return dp[size - 1];
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        return max(robP(nums,0,n-2),robP(nums,1,n-1));
        
    }
};
