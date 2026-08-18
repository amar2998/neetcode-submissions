class Solution {
public:
    void permutation(vector<vector<int>>& ans,int index,vector<int>& nums,int size){
        if(index==size){
            ans.push_back(nums);
        }
        else{
            for(int i=index;i<size;i++){
                swap(nums[i],nums[index]);
                permutation(ans,index+1,nums,size);
                swap(nums[i],nums[index]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        permutation(ans,index,nums,nums.size());
        return ans;
    }
};
