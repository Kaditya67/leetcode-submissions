class Solution {
public:
    vector<int> djk(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto &[neighbor, weight] : adj[node]) {
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        
        return dist;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        int minReachable = INT_MAX, bestCity = -1;

        for (int i = 0; i < n; i++) {
            vector<int> dist = djk(adj, i);
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= distanceThreshold) {
                    reachable++;
                }
            }

            if (reachable <= minReachable) {
                minReachable = reachable;
                bestCity = i;
            }
        }
        return bestCity;
    }
};