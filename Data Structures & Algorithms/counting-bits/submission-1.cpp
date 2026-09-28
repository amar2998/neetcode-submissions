class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            if(i==0 || i==1){
                ans.push_back(i);
                continue;
            }
            if(i%2==0){
                int index=i/2;
                ans.push_back(ans[index]);
            }
            else{
                int index=i/2;
                ans.push_back(ans[index] +1);
            }
        }
        return ans;
    }
};
