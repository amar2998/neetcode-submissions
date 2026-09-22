class Solution {
public:

    int helper(int i,string&  s,vector<int>& memo){
        if(i >= s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }

        if(memo[i]!=-1){
            return memo[i];
        }
        int singleSelect=helper(i+1,s,memo);
        if(i+1 < s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            singleSelect+=helper(i+2,s,memo);
        }
        
        return memo[i]=singleSelect;

    }
    int numDecodings(string s) {
        
        vector<int> memo(s.size(),-1);
        int ans=helper(0,s,memo);
        return ans;
    }
};
