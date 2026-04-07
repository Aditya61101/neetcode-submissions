class Solution {
private:
    vector<int>parent, size;
    int findParent(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return false; // common parent means a cycle
        if(size[pu]>=size[pv]) {
            parent[pv]=pu;
            size[pu]+=size[pv];
        } else {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(auto e:edges) {
            if(!unionBySize(e[0], e[1])) return e;
        }
        return {}; // wont reach for valid test cases
    }
};
