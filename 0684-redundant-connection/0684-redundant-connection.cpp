/*
Intuition:
We are given a graph that started as a tree (connected and acyclic), with one
extra edge added. Our goal is to find that extra edge which forms a cycle.

Optimal Solution (Union-Find / Disjoint Set Union):
- As we add each edge, we use Union-Find to keep track of connected components.
- If two nodes of an edge already share the same root, adding it forms a cycle.

Why Union-Find is optimal:
- Union-Find with path compression and union by rank runs in near-constant time
  (amortized O(α(N)), where α is inverse Ackermann function).
- Much more efficient than DFS in dense graphs.

Time Complexity:
- O(N * α(N)) ≈ O(N) for N edges

Space Complexity:
- O(N) for parent and rank arrays
*/

class Solution {
private:
    // Find root of node with path compression
    int findRoot(int node, vector<int> &parent) {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    // Union two sets and return false if they were already connected
    bool unionNodes(int u, int v, vector<int> &parent, vector<int> &rank) {
        int rootU = findRoot(u, parent);
        int rootV = findRoot(v, parent);

        if (rootU == rootV) {
            return false; // cycle detected
        }

        // Union by rank
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU] += 1;
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();

        // Initialize parent and rank arrays
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Process each edge
        for (const vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If union fails, a cycle is found
            if (!unionNodes(u, v, parent, rank)) {
                return edge;
            }
        }

        return {};
    }
};

/*
// --- ALTERNATE SOLUTION: DFS-Based Cycle Detection (Slower) ---

// -----------------------------------------------------------------------------------------
// MAIN IDEA: IF WE KEEP ADDING AN EDGE TO A GRAPH THAT IS ALREADY CONNECTED, WE GET A CYCLE
// -----------------------------------------------------------------------------------------


class Solution {
private:
    bool hasPath(int src, int target, vector<vector<int>> &graph,
                 vector<bool> &visited) {
        if (src == target) return true;
        visited[src] = true;
        for (int neighbor : graph[src]) {
            if (!visited[neighbor]) {
                if (hasPath(neighbor, target, graph, visited)) return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);

        for (const vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n + 1, false);

            if (!graph[u].empty() and !graph[v].empty()) {
                if (hasPath(u, v, graph, visited)) {
                    return edge;
                }
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};
*/

/*
Base Test Cases:
----------------
Input: edges = [[1,2],[1,3],[2,3]]
Dry Run:
- Union [1,2] → success
- Union [1,3] → success
- Union [2,3] → same root → cycle detected → return [2,3]

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Dry Run:
- Union [1,2], [2,3], [3,4] → success
- Union [1,4] → cycle detected → return [1,4]

Edge Test Cases:
----------------
Input: edges = [[1,2],[2,3],[3,1]]
Dry Run:
- Union [1,2], [2,3] → success
- Union [3,1] → same root → return [3,1]

Input: edges = [[1,4],[3,4],[1,3],[1,2],[4,5]]
Dry Run:
- Union [1,4], [3,4] → success
- Union [1,3] → cycle → return [1,3]
*/

