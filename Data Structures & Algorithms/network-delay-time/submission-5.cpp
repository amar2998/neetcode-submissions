class Solution {
public:
    void helper(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &pq,
    vector<int> &minDist,unordered_map<int,vector<pair<int,int>>> &graph,int n){
        while(!pq.empty()){
            pair<int,int> top=pq.top();
            pq.pop();
            for(auto nabor:graph[top.second]){
                int sum=top.first+nabor.second;
                if(sum<minDist[nabor.first]){
                    minDist[nabor.first]=sum;
                    pq.push({sum,nabor.first});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(int i=0;i<times.size();i++){
            int source=times[i][0];
            int dest=times[i][1];
            int dist=times[i][2];
            graph[source].push_back({dest,dist});
        }
        vector<int> minDist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        minDist[k]=0;
        pq.push({0,k});
        helper(pq,minDist,graph,n);
        int sum=0;
        for(int i=1;i<=n;i++){
            if(minDist[i]==INT_MAX){
                return -1;
            }
            sum=max(minDist[i],sum);
        }
        return sum;
    }
};
