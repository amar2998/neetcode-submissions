class Solution {
public:

    int solve(int amount,vector<int>& coins,int index,vector<vector<int>>& memo){
        if(amount==0){
            return 1;
        }
        // if(amount < 0){
        //     return 0;
        // }
        if(index >= coins.size()){
            return 0;
        }
        if(memo[index][amount]!= -1){
            return memo[index][amount];
        }
        int res=0;
        if(amount >= coins[index]){
            int includeAns=solve(amount-coins[index],coins,index,memo);
            int excludeAns=solve(amount,coins,index+1,memo);
            res=includeAns+excludeAns;
        }
        memo[index][amount]=res;
        return res;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};
