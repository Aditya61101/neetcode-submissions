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
        
        unordered_map<Node*,Node*>newOldNodeMap;
        unordered_map<Node*,Node*>oldNewNodeMap;
        queue<Node*>q;
        
        Node* newRoot = new Node(node->val);
        newOldNodeMap[newRoot]=node;
        oldNewNodeMap[node]=newRoot;
        q.push(newRoot);
        
        while(q.size()) {
            auto newNode = q.front(); q.pop();
            for(auto nei:newOldNodeMap[newNode]->neighbors) {
                if(oldNewNodeMap.count(nei)) {
                    newNode->neighbors.push_back(oldNewNodeMap[nei]);
                    continue;
                }
                Node* newNeighbor = new Node(nei->val);
                newOldNodeMap[newNeighbor]=nei;
                oldNewNodeMap[nei]=newNeighbor;
                newNode->neighbors.push_back(newNeighbor);
                q.push(newNeighbor);
                
            }
        }
        return newRoot;
    }
};
