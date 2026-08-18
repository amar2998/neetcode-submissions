class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> minHeap;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=0;
            int y2=0;
            int diff1=pow((x1-x2),2);
            int diff2=pow((y1-y2),2);
            double dist=sqrt(diff1 + diff2);
            minHeap.push({dist,{points[i][0],points[i][1]}});
        }
        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            pair<int,vector<int>> top=minHeap.top();
            result.push_back(top.second);
            minHeap.pop();
        }
        return result;
    }
};
