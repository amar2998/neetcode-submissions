class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1%n]){
                return nums[i+1%n];
            }
        }
        return nums[0];
    }
};
