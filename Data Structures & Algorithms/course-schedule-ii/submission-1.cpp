class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build a map from course -> list of prerequisites
        unordered_map<int, vector<int>> prereq;
        for (auto& p : prerequisites) {
            prereq[p[0]].push_back(p[1]);
        }
        
        vector<int> order;
        vector<char> state(numCourses, 0);
        // state[i] == 0: unvisited
        // state[i] == 1: visiting
        // state[i] == 2: visited
        
        // try to dfs each course
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (!dfs(i, prereq, state, order))
                    return {};            // cycle detected
            }
        }
        
        return order;
    }

private:
    bool dfs(int node,
             unordered_map<int, vector<int>>& prereq,
             vector<char>& state,
             vector<int>& order)
    {
        if (state[node] == 1)   // hit a node in the current recursion stack → cycle
            return false;
        if (state[node] == 2)   // already fully processed
            return true;
        
        state[node] = 1;        // mark as visiting
        for (int pre : prereq[node]) {
            if (!dfs(pre, prereq, state, order))
                return false;
        }
        state[node] = 2;        // mark as done
        order.push_back(node);  // add to topological order
        return true;
    }
};
