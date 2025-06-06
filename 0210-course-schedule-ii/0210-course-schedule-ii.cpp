class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Step 1: Create adjacency list and indegree array
        for (auto& edge : prerequisites) {
            int a = edge[0], b = edge[1];
            adj[b].push_back(a); // b → a
            indegree[a]++;
        }

        // Step 2: Queue up all nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Step 3: Perform BFS and build topological order
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: Check for cycle
        if (topo.size() == V)
            return topo;
        else
            return {}; // cycle found
    }
};