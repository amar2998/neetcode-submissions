class Solution {
public:

    bool topologicalSort(
        unordered_map<char, unordered_set<char>>& adj,
        stack<char>& stk,
        unordered_map<char, int>& visited,
        char curr
    ) {

        // Currently visiting
        visited[curr] = 1;

        for (char v : adj[curr]) {

            // Cycle detected
            if (visited[v] == 1) {
                return false;
            }

            // Not visited
            if (visited[v] == 0) {
                if (!topologicalSort(adj, stk, visited, v)) {
                    return false;
                }
            }
        }

        // Completely processed
        visited[curr] = 2;

        stk.push(curr);

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> visited;
        stack<char> stk;

        // Add every character to graph
        for (string word : words) {
            for (char ch : word) {
                adj[ch] = unordered_set<char>();
                visited[ch] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int minLength = min(word1.size(), word2.size());

            // Invalid case:
            // ["abc", "ab"]
            if (word1.size() > word2.size() &&
                word1.substr(0, minLength) == word2.substr(0, minLength)) {
                return "";
            }

            // Find first different character
            for (int j = 0; j < minLength; j++) {

                if (word1[j] != word2[j]) {

                    adj[word1[j]].insert(word2[j]);

                    break;
                }
            }
        }

        // DFS for every character
        for (auto& pair : adj) {

            char curr = pair.first;

            if (visited[curr] == 0) {

                if (!topologicalSort(
                        adj,
                        stk,
                        visited,
                        curr
                    )) {
                    return "";
                }
            }
        }

        // Build answer
        string ans = "";

        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};