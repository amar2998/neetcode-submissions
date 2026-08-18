class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int leftMax=height[0];
        int rightMax=height[n-1];
        int totalsum=0;
        while(left < right){
            int sum=0;
            if(height[left] <= height[right]){
                left++;
                leftMax=max(leftMax,height[left]);
                sum=min(leftMax,rightMax)-height[left];
                
            }
            else{
                right--;
                rightMax=max(rightMax,height[right]);
                sum=min(rightMax,leftMax)-height[right];
            }
            if(sum >0){
                totalsum+=sum;
            }
        }
        return totalsum;
        
    }
};
