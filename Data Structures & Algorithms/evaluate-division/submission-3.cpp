// T.C: O(V*(V+E)), S.C: O(V*V)
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++) {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        unordered_map<string,unordered_map<string,double>>ratio;
        for(const auto &[src, _]: adj) {
            queue<pair<string,double>>q;
            unordered_set<string>visited;
            q.push({src,1.0}); visited.insert(src);
            while(q.size()) {
                auto [node,val] = q.front();
                q.pop();
                ratio[src][node]=val;
                for(auto [nei,wt]:adj[node]){
                    if(visited.count(nei)) continue;
                    visited.insert(nei);
                    q.push({nei,val*wt});
                }
            }
        }
        vector<double>ans;
        for(auto query:queries) {
            if(!ratio.count(query[0]) || !ratio[query[0]].count(query[1])) {
                ans.push_back(-1.0); continue;
            }
            ans.push_back(ratio[query[0]][query[1]]);
        }
        return ans;
    }
};