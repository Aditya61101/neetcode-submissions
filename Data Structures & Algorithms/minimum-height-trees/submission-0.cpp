class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            int u=e[0], v=e[1];
            degrees[u]++; degrees[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degrees[i]==1) q.push(i);
        }
        while(!q.empty()){
            // if there are less than or eq to 2 nodes in queue then these are our roots
            if(n<=2) {
                vector<int>roots;
                while(!q.empty()) {
                    roots.push_back(q.front()); q.pop();
                }
                return roots;
            }
            int sz=q.size();
            n-=sz; // nodes to be process is decreased by amount nodes in queue
            for(int i=0;i<sz;i++){
                int curr=q.front(); q.pop();
                for(auto ne:adj[curr]){
                    degrees[ne]--;
                    if(degrees[ne]==1) q.push(ne);
                }
            }
        }
        return {};
    }
};