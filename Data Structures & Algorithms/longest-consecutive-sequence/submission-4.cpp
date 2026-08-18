class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            hashMap[nums[i]]++;
        }
        int maxLength=0;
        for(int num:nums){
            if(!hashMap[num-1]){
                int length=1;
                int curr=num;

                while(hashMap[curr+1]){
                    curr++;
                    length++;
                }
                maxLength=max(maxLength,length);
            }
        }
        return maxLength;
        
    }
};
