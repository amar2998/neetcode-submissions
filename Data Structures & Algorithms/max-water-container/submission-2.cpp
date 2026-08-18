class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int n=heights.size();
        int right=n-1;
        int maxArea=0;
        while(left < right){
            int length=right-left;
            int height=min(heights[left],heights[right]);
            int area=length*height;
            maxArea=max(area,maxArea);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxArea;
        
    }
};
