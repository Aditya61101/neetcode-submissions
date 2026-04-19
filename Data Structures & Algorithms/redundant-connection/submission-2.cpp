// we first treat all the nodes as individual components, then try connecting the edges between nodes.
// if we found that the two nodes already belong to a component then the edge is a redundant edge.
// in this DSU will help.
class DSU {
    vector<int>parent, parentSize;
    int components;
public:
    DSU(int n) {
        parent.resize(n+1); parentSize.resize(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
        components=n;
    }
    int getUltimateParent(int node) {
        if(node==parent[node]) return parent[node];
        return getUltimateParent(parent[node]);
    }
    bool unionBySz(int u, int v) {
        int pu = getUltimateParent(u), pv=getUltimateParent(v);
        // belongs to same component(has same ultimate parent) hence the connection is redundant
        if(pu==pv) return false;
        // we merge pv component to pu, as pu has larger size
        if(parentSize[pu]>=parentSize[pv]) {
            parentSize[pu]+=parentSize[pv];
            parent[pv]=pu;
        } else {
            parentSize[pv]+=parentSize[pu];
            parent[pu]=pv;
        }
        components--;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>redundantEdge(2);
        
        DSU dsu = DSU(n);
        for(auto edge:edges) {
            if(!dsu.unionBySz(edge[0], edge[1])) redundantEdge={edge[0],edge[1]};
        }
        return redundantEdge;
    }
};
