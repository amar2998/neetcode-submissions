class Solution {
public:

    void prims(unordered_map<int, vector<pair<int, int>>> &graph,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &pq,vector<bool> &visited,int u,int& count){
        
        
        pq.push({0,u});
        
        

        while(!pq.empty()){
            pair<int,int> top=pq.top();
            pq.pop();
            if(visited[top.second]==true){
                continue;
            }
            visited[top.second]=true;
            count+=top.first;
            for(auto v:graph[top.second]){
                if(!visited[v.first]){
                    pq.push({v.second,v.first});
                }
            }

        }
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        unordered_map<int, vector<pair<int, int>>> graph;
        int n=points.size();

        for (int i = 0; i < points.size(); i++) {

            for (int j = 0; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                abs(points[i][1] - points[j][1]);
                graph[i].push_back({j,dist});
                
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> visited(n,false);
        int count=0;
        prims(graph,pq,visited,0,count);
        return count;


    // ...
    }
};
