// Onion peeling method, topological trimming
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>degrees(n+1);
        vector<vector<int>>adj(n+1);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degrees[edge[0]]+=1;
            degrees[edge[1]]+=1;
        }
        queue<int>q;
        for(int i=1;i<=n;i++) if(degrees[i]==1) q.push(i);

        while(q.size()) {
            int node = q.front(); q.pop();
            for(int neighbor:adj[node]) {
                // pushing only leaf nodes
                if(--degrees[neighbor]==1) q.push(neighbor);
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(degrees[edges[i][0]]>1 && degrees[edges[i][1]]>1) return {edges[i][0], edges[i][1]};
        }
        return {};
    }
};
