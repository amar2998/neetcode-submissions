class Solution {
public:
    void dfs(unordered_map<string,priority_queue<string,vector<string>,greater<string>>> & graph,string u,vector<string>&ans){
        
        while(!graph[u].empty()){
            string top=graph[u].top();
            graph[u].pop();
            dfs(graph,top,ans);
            
        }
        ans.push_back(u);
        
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>  graph;
        for(auto ticket: tickets){
            string u=ticket[0];
            string v=ticket[1];
            graph[u].push(v);
        }
        string startString="JFK";
        vector<string> ans;
        unordered_map<string,int> visited;
        dfs(graph,startString,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
