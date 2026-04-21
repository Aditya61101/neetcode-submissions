class DSU {
    vector<int>parent, parentSize;
public:
    DSU(int n) {
        parent.resize(n);
        parentSize.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int ultimateParent(int node) {
        if(parent[node]==node) return node;
        return ultimateParent(parent[node]);
    }
    void unionBySz(int u, int v) {
        int pu = ultimateParent(u), pv = ultimateParent(v);
        if(pu==pv) return;
        if(parentSize[pu]>=parentSize[pv]) {
            parentSize[pu]+=parentSize[pv];
            parent[pv]=pu;
        } else {
            parentSize[pv]+=parentSize[pu];
            parent[pu]=pv;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu = DSU(n);
        unordered_map<string,int>ump;
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                if(ump.count(accounts[i][j])) {
                    dsu.unionBySz(ump[accounts[i][j]], i);
                } else {
                    ump[accounts[i][j]] = i;
                }
            }
        }
        // aggregate emails
        vector<vector<string>>emails(n);
        for(auto it:ump) {
            int up = dsu.ultimateParent(it.second);
            // string email = it.first;
            emails[up].push_back(it.first);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++) {
            if(emails[i].empty()) continue;
            string accountName = accounts[i][0];
            vector<string>res;
            res.push_back(accountName);
            sort(emails[i].begin(),emails[i].end());
            res.insert(res.end(), emails[i].begin(),emails[i].end());
            ans.push_back(res);
        }
        return ans;
    }
};