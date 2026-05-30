class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> clones;
        queue<Node*> q;

        // Step 1: Clone the first node and add to map
        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            // Step 2: Visit all neighbors
            for (Node* neighbor : current->neighbors) {
                // If neighbor hasn't been cloned yet
                if (!clones.count(neighbor)) {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                // Step 3: Add the cloned neighbor to current clone's neighbors
                clones[current]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};
