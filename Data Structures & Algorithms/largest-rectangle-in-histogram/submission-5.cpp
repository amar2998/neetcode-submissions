class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            int breadth=1;
            int left=i-1;
            int right=i+1;
            while(left >= 0 && heights[left] >=heights[i]){
                breadth++;
                left--;
            }
            while(right < heights.size() && heights[right] >=heights[i]){
                breadth++;
                right++;
            }
            int area=length * breadth;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
