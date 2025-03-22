class Solution {
public:
    bool dfs(vector<bool>& isVisited, vector<vector<int>>& adj, int node, vector<int>& component) {
        isVisited[node] = true;
        component.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!isVisited[neighbor]) {
                dfs(isVisited, adj, neighbor, component);
            }
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> isVisited(n, false);
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                vector<int> component;
                dfs(isVisited, adj, i, component);

                bool isComplete = true;
                int size = component.size();
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) count++;
            }
        }

        return count;
    }
};
