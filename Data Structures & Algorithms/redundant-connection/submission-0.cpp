class Solution {
public:

    bool DFS(unordered_map<int, vector<int>>& graph,
             vector<bool>& visited,
             int u,
             int target) {

        if (u == target) {
            return true;
        }

        visited[u] = true;

        for (int v : graph[u]) {
            if (!visited[v]) {
                if (DFS(graph, visited, v, target)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> graph;

        int n = edges.size();

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n + 1, false);

            // If u and v are already connected,
            // adding this edge creates a cycle.
            if (DFS(graph, visited, u, v)) {
                return edge;
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};