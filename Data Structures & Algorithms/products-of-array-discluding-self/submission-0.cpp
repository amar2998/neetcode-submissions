class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        int curr=1;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                prefix.push_back(curr);
            }
            else{
                curr=nums[i-1]*curr;
                prefix.push_back(curr);
            }
        }
        curr=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                suffix.push_back(curr);
            }
            else{
                curr=curr*nums[i+1];
                suffix.push_back(curr);
            }
        }
        reverse(suffix.begin(),suffix.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int prod=prefix[i]*suffix[i];
            ans.push_back(prod);
        }
        return ans;
        
    }
};
