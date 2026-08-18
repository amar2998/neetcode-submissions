class Solution {
public:

    void solution(vector<vector<int>> & ans,vector<int>& nums,int target,int i,vector<int>& helper,int sum){
        if(sum==target){
            ans.push_back(helper);
            return;
        }
        if(i >= nums.size() || sum>target){
            return;
        }
        else{
            helper.push_back(nums[i]);
            sum+=nums[i];
            solution(ans,nums,target,i+1,helper,sum);
            helper.push_back(nums[i]);
            sum+=nums[i];
            solution(ans,nums,target,i,helper,sum);
            helper.pop_back();
            helper.pop_back();
            sum-=nums[i];
            sum-=nums[i];
            solution(ans,nums,target,i+1,helper,sum);


        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int index=0;
        vector<int> helper;
        int sum=0;
        solution(ans,nums,target,index,helper,sum);
        return ans;
    }
};
