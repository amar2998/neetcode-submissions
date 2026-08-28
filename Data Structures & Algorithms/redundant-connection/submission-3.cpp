class Solution {
public:

    bool cycle(unordered_map<int,vector<int>>& graph,int u,int target,vector<bool>& visited){
        if(u==target){
            return true;
        }
        visited[u]=true;
        for( int j:graph[u]){
            if(!visited[j]){
                if(cycle(graph,j,target,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        int n=edges.size();

        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            vector<bool> visited(n+1,false);
            if(cycle(graph,u,v,visited)){
                return i;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
        
    }
};
