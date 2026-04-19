class DSU {
    vector<int>parent;
    vector<int>parSize;
    int components;
public:
    DSU(int n) {
        components = n;
        parSize.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int getUltimateParent(int node) {
        if(node==parent[node]) return node;
        return getUltimateParent(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int pu = getUltimateParent(u), pv = getUltimateParent(v);
        if(pu==pv) return false;
        components--;
        if(parSize[pu]>=parSize[pv]) {
            parSize[pu]+=parSize[pv];
            parent[pv] = pu;
        } else {
            parSize[pv]+=parSize[pu];
            parent[pu]=pv;
        }
        // merging has happened
        return true;
    }
    int getComponents() {
        return components;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // for a valid tree with n nodes, we have at most n-1 edges
        if(n-1<edges.size()) return false;
        DSU dsu = DSU(n);
        for(auto edge:edges) {
            // if merging failed this means these nodes were already in that component
            // so merging them again will lead to a cycle
            if(!dsu.unionBySize(edge[0], edge[1])) {
                return false;
            }
        }
        // a graph is a valid tree only when it has a single component
        return dsu.getComponents()==1;
    }
};
