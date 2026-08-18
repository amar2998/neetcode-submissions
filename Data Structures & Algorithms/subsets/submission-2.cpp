class Solution {
public:
    void createSubsets(vector<int>& sub,vector<int>& nums,vector<vector<int>> &ans,int index,int n){
        if(index==n){
            ans.push_back(sub);
        }
        else{
            sub.push_back(nums[index]);
            createSubsets(sub,nums,ans,index+1,n);
            sub.pop_back();
            createSubsets(sub,nums,ans,index+1,n);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        int n=nums.size();
        vector<int> sub;
        createSubsets(sub,nums,ans,index,n);     
        return ans;         
    }
};
