class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjL(n);
        vector<bool>vis(n, false);
        for(auto &e:edges) {
            adjL[e[0]].push_back(e[1]);
            adjL[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=true;
        while(!q.empty()) {
            auto [curr, p]=q.front();
            q.pop();
            for(int &ne:adjL[curr]) {
                if(vis[ne] && p!=ne) return false;
                if(!vis[ne]) {
                    q.push({ne, curr});
                    vis[ne]=true;
                }
            }
        }
        for(auto v:vis) if(!v) return false;
        return true;
    }
};
