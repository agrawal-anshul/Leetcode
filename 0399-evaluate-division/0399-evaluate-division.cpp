/*
Intuition and Key Observations
------------------------------
We are given equations like:
    a / b = 2.0
    b / c = 3.0
and we must answer queries like:
    a / c, c / a, x / y, ...

Key idea:
- Every equation "u / v = k" describes a relationship between two variables.
- We can see each variable as a node in a graph.
- The equation "u / v = k" becomes a directed edge:
      u --(k)--> v   meaning  u / v = k
      v --(1/k)--> u meaning  v / u = 1/k
- Any path from x to y corresponds to multiplying edge weights along the path,
  giving x / intermediate1 * intermediate1 / intermediate2 * ... * last / y.

For example:
  a / b = 2.0,  b / c = 3.0,  c / d = 4.0
  Graph edges:
    a -> b (2.0), b -> a (0.5)
    b -> c (3.0), c -> b (1/3.0)
    c -> d (4.0), d -> c (0.25)

To compute a / d:
  Path: a -> b -> c -> d
  Value: (2.0) * (3.0) * (4.0) = 24.0

So the problem reduces to:
- Build a weighted directed graph from all equations.
- For each query (start, end), find a path from start to end, and multiply
  the edge weights along the path.

Algorithm (BFS per Query)
-------------------------
1. Build the graph:
   - Use unordered_map<string, vector<pair<string, double>>>.
   - For each equation (u, v) with value k:
       add edge u -> v with weight k
       add edge v -> u with weight 1.0 / k

2. Answer queries using BFS:
   For query (start, end):
   - If either start or end does not appear in the graph, answer is -1.0.
   - If start == end and it exists in graph, answer is 1.0.
   - Otherwise:
       * Perform BFS starting from start.
       * Queue stores pairs (node, current_ratio), where current_ratio is
         start / node computed along the path from start to this node.
       * Initially push (start, 1.0) since start / start = 1.0.
       * Maintain a visited set to avoid revisiting nodes.
       * While queue is not empty:
           - Pop front (curr, ratio).
           - If curr == end, return ratio.
           - For each neighbor (next, weight) from curr:
               if next not visited:
                 new_ratio = ratio * weight (because
                             start/curr * curr/next = start/next)
                 push (next, new_ratio) into queue.
                 mark next visited.
       * If BFS finishes with no path, return -1.0.

Why BFS works:
- Any valid path gives a correct ratio, and all edges correctly represent
  the division relationships.
- There is no need for shortest path semantics; we only need one path.
- BFS or DFS both work; BFS is used here for predictable traversal.

Time Complexity
---------------
Let:
- N be the number of given equations.
- Q be the number of queries.

Building the graph:
- We insert two directed edges per equation.
- This is O(N).

For each query:
- In the worst case, BFS can visit every node and every edge in the connected
  component containing the start node.
- Total nodes can be up to O(N) and edges up to O(N), so each BFS is O(N).

Overall time complexity:
- O(N + Q * N) in the worst case.
  (For typical constraints this is efficient enough.)

Space Complexity
----------------
- Graph storage: O(N) edges and the associated nodes.
- Visited set for BFS: O(N) in the worst case per query.
- Queue for BFS: O(N) in the worst case.

Total extra space: O(N).

The solution is efficient for typical constraints and easy to understand:
- Graph construction clearly mirrors the equations.
- BFS per query cleanly computes ratios along paths.
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        
        // Build adjacency list to represent the weighted directed graph.
        // Each key is a variable, and it maps to a list of (neighbor, weight)
        // representing: variable / neighbor = weight.
        unordered_map<string, vector<pair<string, double>>> graph;

        // Fill the graph from the given equations and values.
        // For each equation u / v = k:
        //   add edge u -> v with weight k
        //   add edge v -> u with weight 1.0 / k
        int eqCount = (int)equations.size();
        for (int i = 0; i < eqCount; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double k = values[i];

            // Add edge u -> v with multiplication factor k.
            graph[u].push_back(make_pair(v, k));

            // Add reverse edge v -> u with factor 1.0 / k.
            graph[v].push_back(make_pair(u, 1.0 / k));
        }

        // Prepare the answer container, one entry per query.
        int qCount = (int)queries.size();
        vector<double> result(qCount, -1.0);

        // Process each query independently using BFS to find a path between
        // the two queried variables and compute the ratio along that path.
        for (int i = 0; i < qCount; i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            // If either variable does not exist in the graph, the result
            // is immediately -1.0 because no relationship is known.
            if (graph.find(start) == graph.end() or
                graph.find(end) == graph.end()) {
                result[i] = -1.0;
                continue;
            }

            // If both variables are the same and they exist in the graph,
            // the ratio is 1.0 by definition (x / x = 1).
            if (start == end) {
                result[i] = 1.0;
                continue;
            }

            // Use BFS to search for any path from start to end while
            // accumulating the ratio along the way.
            result[i] = bfsComputeRatio(start, end, graph);
        }

        // Return the computed results for all queries.
        return result;
    }

private:
    // Helper function to perform BFS on the graph to compute the ratio
    // start / end if a path exists. If no path is found, returns -1.0.
    double bfsComputeRatio(const string &start,
                           const string &end,
                           unordered_map<string,
                           vector<pair<string, double>>> &graph) {
        
        // Queue will store (current variable, accumulated ratio from start).
        queue<pair<string, double>> bfsQueue;

        // Start from the "start" node with ratio 1.0 because start/start=1.
        bfsQueue.push(make_pair(start, 1.0));

        // Use a visited set to avoid revisiting nodes and getting stuck in
        // cycles.
        unordered_set<string> visited;
        visited.insert(start);

        // Standard BFS traversal.
        while (!bfsQueue.empty()) {
            pair<string, double> frontPair = bfsQueue.front();
            bfsQueue.pop();

            string currVar = frontPair.first;
            double currRatio = frontPair.second;

            // If we reached the target variable, the current ratio is the
            // desired start / end value.
            if (currVar == end) {
                return currRatio;
            }

            // Explore all neighbors of the current variable.
            vector<pair<string, double>> &neighbors = graph[currVar];
            int neighCount = (int)neighbors.size();
            for (int j = 0; j < neighCount; j++) {
                string nextVar = neighbors[j].first;
                double edgeWeight = neighbors[j].second;

                // Only proceed if this neighbor has not been visited yet.
                if (visited.find(nextVar) == visited.end()) {
                    // Mark neighbor as visited to avoid revisiting.
                    visited.insert(nextVar);

                    // Compute new ratio for nextVar:
                    //   start/currVar * currVar/nextVar
                    // = currRatio * edgeWeight.
                    double nextRatio = currRatio * edgeWeight;

                    // Push neighbor along with its ratio into the queue.
                    bfsQueue.push(make_pair(nextVar, nextRatio));
                }
            }
        }

        // If BFS finishes without visiting "end", there is no path between
        // start and end, so the ratio is undefined, represented by -1.0.
        return -1.0;
    }
};

/*
Base Test Cases
---------------
1) Simple chain with direct and indirect queries
   Equations:
     a / b = 2.0
     b / c = 3.0
   Queries:
     1) a / c
     2) b / a
     3) a / a

   Dry Run:
   - Graph edges:
       a -> b (2.0), b -> a (0.5)
       b -> c (3.0), c -> b (1/3.0)

   Query 1: a / c
   - start = "a", end = "c" (both present, not equal).
   - BFS queue initially: [("a", 1.0)], visited = {"a"}.
   - Pop ("a", 1.0): not equal to "c".
     Neighbors of a: ("b", 2.0).
     - b not visited:
       visited = {"a", "b"}
       nextRatio = 1.0 * 2.0 = 2.0
       push ("b", 2.0)
   - Pop ("b", 2.0): not equal to "c".
     Neighbors of b: ("a", 0.5), ("c", 3.0)
     - a already visited, skip.
     - c not visited:
       visited = {"a", "b", "c"}
       nextRatio = 2.0 * 3.0 = 6.0
       push ("c", 6.0)
   - Pop ("c", 6.0): equals end "c".
     Return 6.0, so a/c = 6.0.

   Query 2: b / a
   - start = "b", end = "a".
   - BFS queue: [("b", 1.0)], visited = {"b"}.
   - Pop ("b", 1.0): not equal to "a".
     Neighbors: ("a", 0.5), ("c", 3.0)
     - a not visited:
       visited = {"b", "a"}
       nextRatio = 1.0 * 0.5 = 0.5
       push ("a", 0.5)
     - c not visited yet but will be processed later if needed.
   - Pop ("a", 0.5): equals end "a".
     Return 0.5, so b/a = 0.5.

   Query 3: a / a
   - start = "a", end = "a".
   - Since start == end and "a" exists in graph, answer is 1.0.

2) Disconnected variables
   Equations:
     a / b = 2.0
   Queries:
     1) a / c
     2) c / a

   Dry Run:
   - Graph has nodes: {"a", "b"}.

   Query 1: a / c
   - "c" not in graph, so result = -1.0.

   Query 2: c / a
   - "c" not in graph, so result = -1.0.

Edge Test Cases
----------------
1) Repeated variables in equation set (redundant information)
   Equations:
     a / b = 2.0
     a / b = 2.0   (duplicate)
   Queries:
     b / a

   Dry Run:
   - Graph will contain two edges a->b (2.0) and two edges b->a (0.5).
   - Query b/a:
     start = "b", end = "a".
     BFS queue: [("b", 1.0)], visited = {"b"}.
     Neighbors of b: two ("a", 0.5) edges.
     The first neighbor a is unvisited:
       visited = {"b", "a"}
       nextRatio = 1.0 * 0.5 = 0.5
       push ("a", 0.5)
     Pop ("a", 0.5): equals end, return 0.5.
   - Duplicate edges do not affect correctness, only add redundant work.

2) Query where start and end equal but variable is unknown
   Equations:
     a / b = 2.0
   Queries:
     c / c

   Dry Run:
   - Graph has nodes {"a", "b"}.
   - Query: start = "c", end = "c".
   - graph.find("c") == graph.end(), so immediate result = -1.0 because
     no information about "c" is known.

3) Single equation, direct query
   Equations:
     x / y = 4.5
   Queries:
     1) x / y
     2) y / x

   Dry Run:
   - Graph:
       x -> y (4.5)
       y -> x (1/4.5)

   Query 1: x / y
   - start = "x", end = "y".
   - BFS: queue [("x", 1.0)], visited {"x"}
   - Pop ("x", 1.0). Neighbors: ("y", 4.5)
   - y not visited:
       visited {"x", "y"}
       nextRatio = 1.0 * 4.5 = 4.5
       push ("y", 4.5)
   - Pop ("y", 4.5) equals end -> return 4.5.

   Query 2: y / x
   - start = "y", end = "x".
   - BFS: queue [("y", 1.0)], visited {"y"}
   - Pop ("y", 1.0). Neighbors: ("x", 1/4.5)
   - x not visited:
       visited {"y", "x"}
       nextRatio = 1.0 * (1/4.5)
       push ("x", 1/4.5)
   - Pop ("x", 1/4.5) equals end -> return 1/4.5.
*/
