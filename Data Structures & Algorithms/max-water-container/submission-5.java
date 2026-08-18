class Solution {
    public int maxArea(int[] heights) {
        int left=0;
        int right=heights.length-1;
        int maxArea=Integer.MIN_VALUE;
        while(left < right){
            int length=Math.min(heights[left],heights[right]);
            int breadth=right-left;
            int area=length*breadth;
            maxArea=Math.max(area,maxArea);
            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
}
