class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // curr, parent
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=true;
        while(q.size()) {
            auto [curr,parent] = q.front();
            q.pop();
            for(int nei:adj[curr]) {
                // this nei was visited from some other path and hence had a parent, 
                // so visiting it now will make it have more than one parent
                // which is not a criteria for being node of a valid tree
                if(nei!=parent && vis[nei]) return false;
                if(nei!=parent) {
                    q.push({nei,curr});
                    vis[nei] = true;
                }
            }
        }
        for(bool vi:vis) if(!vi) return false;
        return true;
    }
};
