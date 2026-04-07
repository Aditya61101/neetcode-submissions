class Solution {
private:
    vector<vector<int>>memo;
    bool dfs(int src, int tar, vector<vector<int>>&adjL) {
        if(src==tar) return memo[src][tar]=true;
        if(memo[src][tar]!=-1) return memo[src][tar];
        for(int ne: adjL[src]) {
            if(dfs(ne, tar, adjL)) return memo[src][tar]=true;
        }
        return memo[src][tar]=false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int qs=queries.size(), n=numCourses;
        memo.assign(n, vector<int>(n,-1));
        vector<bool>ans(qs, false);
        if(prerequisites.size()==0) return ans;

        vector<vector<int>>adjL(n);
        for(auto &p:prerequisites) {
            adjL[p[0]].push_back(p[1]);
        }
        
        for(int i=0;i<qs;i++) {
            ans[i]=dfs(queries[i][0], queries[i][1], adjL);
        }
        return ans;
    }
};