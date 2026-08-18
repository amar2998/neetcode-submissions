class Solution {
public:
    vector<int> nextSmallerElement(vector<int >& height){
        int n=height.size();
        vector<int> ans(n,n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() &&  height[stk.top()] > height[i]){
                int index=stk.top();
                stk.pop();
                ans[index]=i;
            }
            stk.push(i);
        }
        return ans;
    }

    vector<int> previousSmallerElement(vector<int>& heights){
        int n=heights.size();
        // reverse(heights.begin(),heights.end());
        vector<int> ans(n,-1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() &&  heights[stk.top()] > heights[i]){
                int index=stk.top();
                stk.pop();
                ans[index]=i;
            }
            stk.push(i);
        }
        return ans;

    }
    int largestRectangleArea(vector<int>& heights) {
        // for(int i=0;i<heights.size();i++){
        //     int length=heights[i];
        //     int breadth=1;
        //     int left=i-1;
        //     int right=i+1;
        //     while(left >= 0 && heights[left] >=heights[i]){
        //         breadth++;
        //         left--;
        //     }
        //     while(right < heights.size() && heights[right] >=heights[i]){
        //         breadth++;
        //         right++;
        //     }
        //     int area=length * breadth;
        //     maxArea=max(maxArea,area);
        // }
        int maxArea=0;

        vector<int> next;
        next=nextSmallerElement(heights);
        vector<int> prev=previousSmallerElement(heights);

        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            int breadth=next[i]-prev[i]-1;
            int area=length * breadth;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};
