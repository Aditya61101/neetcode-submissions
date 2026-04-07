class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int qs=queries.size();
        vector<bool>ans(qs, false);
        if(prerequisites.size()==0) return ans;

        int n=numCourses;
        vector<vector<bool>>reachable(n, vector<bool>(n, false));
        vector<int>dep(n);
        vector<vector<int>>adjL(n);
        for(auto &p:prerequisites) {
            dep[p[0]]++;
            adjL[p[1]].push_back(p[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++) if(dep[i]==0) q.push(i);
        while(!q.empty()) {
            int cu=q.front(); 
            q.pop();
            for(auto ne:adjL[cu]){
                reachable[ne][cu]=true;
                for(int i=0;i<n;i++) if(reachable[cu][i]) reachable[ne][i]=true;
                dep[ne]--;
                if(dep[ne]==0) q.push(ne);
            }
        }

        for(int i=0;i<qs;i++) {
            if(reachable[queries[i][0]][queries[i][1]]) ans[i]=true;
        }
        return ans;
    }
};