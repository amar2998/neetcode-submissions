class Solution {
public:
    bool dfs(int u,vector<bool>&visited,vector<bool>& path,vector<vector<int>>& graph){
        visited[u]=true;
        path[u]=true;

        for(int v:graph[u]){
            if(path[v]){
                return true;
            }
            if(!visited[v]){
                if(dfs(v,visited,path,graph)){
                    return true;
                }
            }

        }
        path[u]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //build graph
        vector<vector<int>> graph(numCourses);
        for(auto p:prerequisites){
            int prereq=p[1];
            int course=p[0];
            graph[prereq].push_back(course);
        }


        vector<bool >visited(numCourses,false);
        vector<bool >path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,path,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
