class Solution {
    double bfs(string &src, string &target, unordered_map<string,vector<pair<string,double>>>&adj) {
        queue<pair<string,double>>q;
        unordered_set<string>visited;
        q.push({src,1});
        visited.insert(src);
        while(q.size()) {
            auto [node,val] = q.front();
            q.pop();
            if(node==target) return val;
            for(auto [neighbor, wt]:adj[node]) {
                if(visited.count(neighbor)) continue;
                visited.insert(neighbor);
                q.push({neighbor,val*wt});
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++) {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double>ans;
        for(auto query:queries) {
            if(!adj.count(query[0]) || !adj.count(query[1])) {
                ans.push_back(-1.0); continue;
            }
            double value = bfs(query[0],query[1],adj);
            ans.push_back(value);
        }
        return ans;
    }
};