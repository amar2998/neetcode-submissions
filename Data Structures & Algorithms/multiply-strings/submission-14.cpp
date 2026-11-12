class Solution {
public:
    
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int n=num2.size();
        int m=num1.size();
        vector<int> res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i+j+1]+=(num2[i]-'0')*(num1[j]-'0');
            }
        }

        for( int i=n+m-1;i>0;i--){
            res[i-1]=res[i-1]+res[i]/10;
            res[i]=res[i]%10;
        }
        int start=0;
        while(start < res.size() && res[start]==0){
            start++;
        }
        string ans;
        for(int i=start;i<res.size();i++){
            ans+='0'+res[i];
        }
        return ans;
    }
};
