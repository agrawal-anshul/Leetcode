/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* createCloneUsingDFS(Node* node, map<Node*,Node*>& mp){
        if(node == nullptr)return node;
        
        // clonednode already exists in map
        if(mp.find(node) != mp.end()){
            return mp[node];
        }

        
        Node* clonedNode = new Node(node->val);
        mp[node] = clonedNode;
        
        for(auto neighbor : node->neighbors){
            Node* clonedNeighbor = createCloneUsingDFS(neighbor, mp);
            clonedNode->neighbors.push_back(clonedNeighbor);
        }
        return clonedNode;
    }

public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mp;
        return createCloneUsingDFS(node, mp);
    }
};