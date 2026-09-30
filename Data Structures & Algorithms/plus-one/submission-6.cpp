class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long sum=0;
        int n=digits.size();
        int i=n-1;
        int inc=1;
        while(i>=0){
            sum+=digits[i]*inc;
            inc*=10;
            i--;
        }
        
        sum+=1;
        vector<int> ans;
        while(sum!=0){ 
            int dig=sum%10;
            ans.push_back(dig);
            sum=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
