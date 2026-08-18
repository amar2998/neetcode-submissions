#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map1;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            int req=target-curr;
            
            if(map1.find(req)!=map1.end()){
                if(i!=map1[req]){

                    return {i,map1[req]};
                }
            }
        }
    }
};
