class Solution {
public:

    void DFS(vector<bool>& visited,unordered_map<int,vector<int>>& graph,int u,int parent){
        visited[u]=true;

        for(int v:graph[u]){
            if(!visited[v]){
                DFS(visited,graph,v,u);
            }
        }
        
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>> graph;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i< n; i++){
            if(!visited[i]){
                DFS(visited,graph,i,-1);
                count++;
            }
        }
        return count;

    }
};
