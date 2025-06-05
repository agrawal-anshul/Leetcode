/*
INTUITION:
To clone a graph, we need to create a deep copy where each node in the original graph
has a corresponding new node in the cloned graph, and all connections are preserved.

KEY OBSERVATIONS:
1. We need to visit every node exactly once to avoid infinite loops in cyclic graphs
2. We must maintain a mapping between original nodes and their cloned counterparts
3. For each node, we clone it first, then recursively clone all its neighbors
4. We use DFS traversal to systematically visit all connected nodes

ALGORITHM:
1. Use a hash map to store the mapping: original_node -> cloned_node
2. Start DFS from the given node
3. For each node:
   - If already cloned (exists in map), return the cloned version
   - Create a new node with the same value
   - Add it to the mapping immediately (before processing neighbors)
   - Recursively clone all neighbors and add them to the new node's neighbor list
4. Return the cloned node

TIME COMPLEXITY: O(V + E) where V = number of vertices, E = number of edges
- We visit each vertex exactly once: O(V)
- We traverse each edge exactly once during neighbor processing: O(E)
- Hash map operations are O(1) on average

SPACE COMPLEXITY: O(V) where V = number of vertices
- Hash map stores at most V entries: O(V)
- Recursion stack depth is at most V in the worst case (linear graph): O(V)
- The cloned graph itself takes O(V + E) space but that's the required output
*/

class Solution {
private:
    // Hash map to store mapping from original node to cloned node
    unordered_map<Node*, Node*> originalToCloned;
    
    // Helper function to perform DFS and clone nodes recursively
    Node* performDfsCloning(Node* currentNode) {
        // Base case: if current node is null, return null
        if (currentNode == nullptr) {
            return nullptr;
        }
        
        // If this node has already been cloned, return the cloned version
        if (originalToCloned.find(currentNode) != originalToCloned.end()) {
            return originalToCloned[currentNode];
        }
        
        // Create a new node with the same value as the current node
        Node* clonedNode = new Node(currentNode->val);
        
        // Add the mapping to prevent infinite recursion in cyclic graphs
        originalToCloned[currentNode] = clonedNode;
        
        // Recursively clone all neighbors and add them to the cloned node
        for (Node* neighbor : currentNode->neighbors) {
            // Recursively clone each neighbor
            Node* clonedNeighbor = performDfsCloning(neighbor);
            // Add the cloned neighbor to the current cloned node's neighbor list
            clonedNode->neighbors.push_back(clonedNeighbor);
        }
        
        // Return the fully constructed cloned node
        return clonedNode;
    }
    
public:
    Node* cloneGraph(Node* node) {
        // Clear the mapping for each test case (if reusing the same instance)
        originalToCloned.clear();
        
        // Start the DFS cloning process from the given node
        return performDfsCloning(node);
    }
};

/*
BASE TEST CASES:

Test Case 1: [[2,4],[1,3],[2,4],[1,3]]
- Node 1 connects to [2,4], Node 2 connects to [1,3], Node 3 connects to [2,4], Node 4 connects to [1,3]
- DFS starts at node 1
- Clone node 1, add to map: {1->1'}
- Process neighbors [2,4]:
  - Clone node 2, add to map: {1->1', 2->2'}
  - Process node 2's neighbors [1,3]:
    - Node 1 already cloned, return 1'
    - Clone node 3, add to map: {1->1', 2->2', 3->3'}
    - Process node 3's neighbors [2,4]:
      - Node 2 already cloned, return 2'
      - Clone node 4, add to map: {1->1', 2->2', 3->3', 4->4'}
      - Process node 4's neighbors [1,3]:
        - Node 1 already cloned, return 1'
        - Node 3 already cloned, return 3'
      - Node 4' gets neighbors [1', 3']
    - Node 3' gets neighbors [2', 4']
  - Node 2' gets neighbors [1', 3']
  - Back to node 1, process neighbor 4:
    - Node 4 already cloned, return 4'
- Node 1' gets neighbors [2', 4']
- Return 1' (root of cloned graph)

Test Case 2: [[]]
- Single node with no neighbors
- Clone the node, empty neighbor list
- Return the cloned node

Test Case 3: []
- Empty graph (node is null)
- Return null immediately

EDGE TEST CASES:

Test Case 1: Single Node Loop [[1]]
- Node 1 connects to itself
- Clone node 1, add to map: {1->1'}
- Process neighbor [1]:
  - Node 1 already cloned, return 1'
- Node 1' gets neighbor [1'] (points to itself)
- Return 1'

Test Case 2: Two Node Cycle [[2],[1]]
- Node 1 connects to [2], Node 2 connects to [1]
- Clone node 1, add to map: {1->1'}
- Process neighbor [2]:
  - Clone node 2, add to map: {1->1', 2->2'}
  - Process node 2's neighbor [1]:
    - Node 1 already cloned, return 1'
  - Node 2' gets neighbor [1']
- Node 1' gets neighbor [2']
- Return 1' (both nodes properly reference each other)

Test Case 3: Linear Chain [[2],[3],[]]
- Node 1->2->3 (no cycles)
- Clone node 1, add to map: {1->1'}
- Process neighbor [2]:
  - Clone node 2, add to map: {1->1', 2->2'}
  - Process neighbor [3]:
    - Clone node 3, add to map: {1->1', 2->2', 3->3'}
    - Node 3 has no neighbors
  - Node 2' gets neighbor [3']
- Node 1' gets neighbor [2']
- Return 1' (linear chain preserved)
*/