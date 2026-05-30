class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();               // #nodes == #edges for this problem
        vector<vector<int>> adj(n);         // zero‑based [0..n-1]

        for (auto& e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            // add the new edge
            adj[u].push_back(v);
            adj[v].push_back(u);

            // fresh seen array (also size n)
            vector<bool> seen(n, false);
            // if adding this edge creates a cycle, return it
            if (dfs(u, -1, adj, seen)) {
                return {u+1, v+1};         // convert back to 1-based labels
            }
        }
        return {};
    }

private:
    bool dfs(int node,
             int parent,
             vector<vector<int>>& adj,
             vector<bool>& seen) 
    {
        if (seen[node]) 
            return true;                  // cycle detected
        seen[node] = true;
        for (int nei : adj[node]) {
            if (nei == parent) 
                continue;                 // don’t go right back
            if (dfs(nei, node, adj, seen))
                return true;
        }
        return false;
    }
};
