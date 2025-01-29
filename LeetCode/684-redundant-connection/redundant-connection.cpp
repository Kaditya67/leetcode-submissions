class Solution {
public:
    int findPar(int p, vector<int>& par) {
        if (p == par[p]) return p;
        return par[p] = findPar(par[p], par); // Path compression
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(1001); // Assuming node values are <= 1000
        for (int i = 0; i < p.size(); i++)
            p[i] = i; // Initialize each node as its own parent

        vector<int> res;
        for (auto& v : edges) {
            int n1 = findPar(v[0], p); // Find representative of n1
            int n2 = findPar(v[1], p); // Find representative of n2

            if (n1 == n2) // Cycle detected
                res = v;
            else
                p[n1] = n2; // Union operation
        }
        return res;
    }
};
