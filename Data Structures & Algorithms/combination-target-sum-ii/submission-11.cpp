class Solution {
public:
    void solution(int sum,vector<int>& helper,vector<vector<int>>& ans,int index,vector<int>& nums,int target){
        if(sum==target){
            ans.push_back(helper);
            return;
        }
        if(index >= nums.size() || sum > target){
            return;
        }
        else{
            helper.push_back(nums[index]);
            solution(sum+nums[index],helper,ans,index+1,nums,target);
            helper.pop_back();
            // sum-=nums[index];
            while(index < nums.size()-1 && nums[index]==nums[index+1]){
                index++;
            }
            // index++;
            solution(sum,helper,ans,index+1,nums,target);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> helper;
        int sum=0;
        int index=0;
        sort(candidates.begin(),candidates.end());
        solution(sum,helper,ans,index,candidates,target);
        return ans;
    }
};
