class Solution {
private:
    void bfs(int src, vector<vector<int>>& adjL, vector<bool>& v) {
        v[src]=true;
        queue<int>q;
        q.push(src);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int ne:adjL[curr]) {
                if(!v[ne]) {
                    q.push(ne);
                    v[ne]=true;
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<vector<int>>adjL(n);
        for(auto &e:edges) {
            adjL[e[0]].push_back(e[1]);
            adjL[e[1]].push_back(e[0]);
        }
        vector<bool>v(n, false);
        for(int i=0;i<n;i++) {
            if(!v[i]) {
                bfs(i, adjL, v);
                ans+=1;
            }
        }
        return ans;
    }
};
