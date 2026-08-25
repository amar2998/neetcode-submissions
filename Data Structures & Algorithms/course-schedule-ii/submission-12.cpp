class Solution {
public:

    bool DFS(stack<int>& stk,vector<bool>& visited,vector<vector<int>>& graph,int u,vector<bool>& path){
        visited[u]=true;
        path[u]=true;
        for(int v:graph[u]){
            if(path[v]){
                return true;
            }
            if(!visited[v]){
                if(DFS(stk,visited,graph,v,path)){
                    return true;
                }
            }
        }
        path[u]=false;
        stk.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>> graph(numCourses);
        for(auto p:prerequisites){
            int prereq=p[1];
            int course=p[0];
            graph[prereq].push_back(course);
        }
        vector<bool> path(numCourses,false);
        vector<bool> visited(numCourses,false);
        stack<int> stk;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(DFS(stk,visited,graph,i,path)){
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            int top=stk.top();
            ans.push_back(top);
            stk.pop();
        }
        return ans;
    }
};
