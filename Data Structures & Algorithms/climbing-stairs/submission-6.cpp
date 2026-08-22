class Solution {
public:
    int backtract(vector<int>&dpArr,int n){
        if(n==1 || n==2){
            return n;
        }
        if(dpArr[n]!=-1){
            return dpArr[n];
        }
        return dpArr[n]=backtract(dpArr,n-1) + backtract(dpArr,n-2);
        
    }
    int climbStairs(int n) {
        vector<int> dpArr(n+1,-1);
        return backtract(dpArr,n);
        
    }
};
