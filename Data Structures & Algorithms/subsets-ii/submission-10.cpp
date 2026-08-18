class Solution {
public:
    void subsets(vector<int>& nums,vector<vector<int>>& ans,vector<int>& sub,int size,int index){
        if(index==size){
            ans.push_back(sub);
            return;
        }
        else{
            sub.push_back(nums[index]);
            subsets(nums,ans,sub,size,index+1);
            sub.pop_back();
            int i=index;
            while(i< size-1 && nums[i]==nums[i+1]){
                i++;
            }
            // i++;
            subsets(nums,ans,sub,size,i+1);

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        int n=nums.size();
        int index=0;
        subsets(nums,ans,sub,n,index);
        return ans;
        
    }
};
