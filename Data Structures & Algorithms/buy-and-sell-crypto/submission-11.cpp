class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int i=0;
        int j=1;
        int maxprofit=0;
        int n=prices.size();
        while(j<n){
            if(prices[j]-prices[i] >=0){
                int profit=prices[j]-prices[i];
                maxprofit=max(maxprofit,profit);
                j++;
            }
            else{
                
                i=j;
                j++;
            }
        }
        return maxprofit;

    }
};
