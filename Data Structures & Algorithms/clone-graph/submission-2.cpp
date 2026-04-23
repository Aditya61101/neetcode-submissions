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
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        // map of old -> new node
        // to keep track whether we have created the clone of current old node
        unordered_map<Node*,Node*>oldNewNodeMap;
        // stores old nodes
        queue<Node*>q;
        
        Node* newRoot = new Node(node->val);
        oldNewNodeMap[node]=newRoot;
        q.push(node);
        
        while(q.size()) {
            auto oldNode = q.front(); q.pop();
            for(auto nei:oldNode->neighbors) {
                if(oldNewNodeMap.count(nei)) {
                    oldNewNodeMap[oldNode]->neighbors.push_back(oldNewNodeMap[nei]);
                    continue;
                }
                Node* newNeighbor = new Node(nei->val);
                oldNewNodeMap[nei]=newNeighbor;
                oldNewNodeMap[oldNode]->neighbors.push_back(newNeighbor);
                q.push(nei);
            }
        }
        return newRoot;
    }
};
