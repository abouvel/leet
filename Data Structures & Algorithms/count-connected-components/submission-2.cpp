class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int components = n;
        
        for (auto& e : edges) {
            if (unite(e[0], e[1], parent, rank))
                --components;     // only decrement when two sets actually merge
        }
        
        return components;
    }

private:
    // Find with path compression
    int findRoot(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x], parent);
        return parent[x];
    }

    // Union by rank; returns true if a merge happened
    bool unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        int ra = findRoot(a, parent);
        int rb = findRoot(b, parent);
        if (ra == rb) 
            return false;        // already in the same set
        
        // attach smaller‐rank tree under larger‐rank root
        if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        } else if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        } else {
            parent[rb] = ra;
            rank[ra]++;
        }
        return true;
    }
};
