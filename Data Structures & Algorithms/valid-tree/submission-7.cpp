class Solution {
public:

    bool detectCycle(unordered_map <int,vector<int>>& graph,int u,vector<bool>& visited,int parent){
        visited[u]=true;
        for(int v:graph[u]){
            if( visited[v]&&v!=parent){
                return true;
            }
            if(!visited[v]){
                if(detectCycle(graph,v,visited,u)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
        unordered_map <int,vector<int>> graph;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(detectCycle(graph,0,visited,-1)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
