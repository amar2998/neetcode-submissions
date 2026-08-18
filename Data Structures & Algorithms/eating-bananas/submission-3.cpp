class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minRate=1;
        int maxRate=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxRate=max(maxRate,piles[i]);
        }
        while(minRate <= maxRate){
            int midRate=minRate+(maxRate-minRate)/2;
            long long hour=0;
            for(int i=0;i<piles.size();i++){
                hour+=(piles[i]+midRate-1)/midRate;
            }
            if(hour <=h){
                maxRate=midRate-1;
            }
            else{
                minRate=midRate+1;
            }
        }
        return minRate;
    }
};
