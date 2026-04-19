// T.C: O(V+E), S.C: O(V+E)
class Solution {
    vector<bool>vis;
    void dfs(int src, vector<vector<int>>&adj) {
        vis[src]=true;
        for(auto nei:adj[src]) {
            if(!vis[nei]) dfs(nei,adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vis.resize(n,false);
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components=0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i,adj);
                components+=1;
            }
        }
        return components;
    }
};
