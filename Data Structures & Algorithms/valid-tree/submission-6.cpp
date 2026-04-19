class Solution {
    bool dfs(vector<vector<int>>&adj, vector<bool>&vis, int curr, int parent) {
        if(vis[curr]) return false;
        vis[curr]=true;
        // exploring the neighbours
        for(int nei: adj[curr]) {
            // this graph has cycles
            if(nei!=parent && !(dfs(adj, vis, nei, curr))) return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // for a valid tree with n nodes, we have at most n-1 edges
        if(n-1<edges.size()) return false;
        vector<vector<int>>adj(n);
        vector<bool>vis(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // cycle detection in an undirected graph
        if(!dfs(adj,vis,0,-1)) return false;
        // a valid tree is never a disjoint set of graph
        for(bool vi:vis) if(!vi) return false;
        return true;
    }
};
