class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> graph;

        for (auto flight : flights) {

            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];

            graph[u].push_back({v, cost});
        }

        // {node, cost}
        queue<pair<int,int>> q;

        q.push({src, 0});

        // cost[node] = cheapest cost to reach node
        // within the current number of stops
        vector<int> cost(n, INT_MAX);

        cost[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {

            int size = q.size();

            // Important:
            // Don't update cost directly while processing
            // the same level.
            vector<int> nextCost = cost;

            while (size--) {

                auto [node, currCost] = q.front();
                q.pop();

                for (auto [nextNode, price] : graph[node]) {

                    int newCost = currCost + price;

                    if (newCost < nextCost[nextNode]) {

                        nextCost[nextNode] = newCost;

                        q.push({nextNode, newCost});
                    }
                }
            }

            cost = nextCost;

            stops++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};