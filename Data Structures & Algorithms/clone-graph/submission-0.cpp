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
        if(!node) return nullptr;
        // stores original node and copied node
        unordered_map<Node*, Node*>cloned;
        cloned[node] = new Node(node->val);
        queue<Node*>q;
        q.push(node);
        while(!q.empty()) {
            Node *curr=q.front();
            q.pop();
            for(auto ne:curr->neighbors){
                if(!cloned.count(ne)){
                    cloned[ne]=new Node(ne->val);
                    q.push(ne);
                }
                cloned[curr]->neighbors.push_back(cloned[ne]);
            }
        }
        return cloned[node];
    }
};
