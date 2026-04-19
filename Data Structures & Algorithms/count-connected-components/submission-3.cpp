class DSU {
    vector<int>parent;
    vector<int>parentSize;
    int components;
public:
    DSU(int n) {
        components = n;
        parent.resize(n); parentSize.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
   
    //  path compression
    int getUltimateParent(int node) {
        if(node==parent[node]) return parent[node];
        return getUltimateParent(parent[node]);
    }

    void unionBySz(int u, int v) {
        int pu=getUltimateParent(u), pv=getUltimateParent(v);
        if(pu==pv) return;
        if(parentSize[pu]>=parentSize[pv]) {
            parentSize[pu]+=parentSize[pv];
            parent[pv]=parent[pu];
        } else {
            parentSize[pv]+=parentSize[pu];
            parent[pu]=parent[pv];
        }
        components--;
    }
    int getComponents() {
        return components;
    }

};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu = DSU(n);
        for(auto edge:edges) {
            dsu.unionBySz(edge[0],edge[1]);
        }
        return dsu.getComponents();
    }
};
