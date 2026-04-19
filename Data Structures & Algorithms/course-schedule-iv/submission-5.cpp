class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, 
    vector<vector<int>>& queries) {
        vector<int>dep(numCourses);
        vector<vector<int>>adj(numCourses);
        vector<vector<bool>>reachable(numCourses, vector<bool>(numCourses, false));
        for(auto pre:prerequisites) {
            dep[pre[1]]+=1;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int>q;
        for(int i=0;i<dep.size();i++) if(dep[i]==0) q.push(i);
        while(q.size()) {
            int currentCourse = q.front();
            q.pop();
            for(int incomingCourse:adj[currentCourse]) {
                // this marks only adjacent dependent courses as true
                // reachable[parent][child]
                reachable[currentCourse][incomingCourse] = true;
                // u->v, v->w => u->w
                for(int i=0;i<numCourses;i++) if(reachable[i][currentCourse]) reachable[i][incomingCourse] = true;
                dep[incomingCourse]-=1;
                if(dep[incomingCourse]==0) {
                    q.push(incomingCourse);
                }
            }
        }
        int queryLength = queries.size();
        vector<bool>answers(queryLength);
        for(int i=0;i<queryLength;i++) {
            answers[i] = reachable[queries[i][0]][queries[i][1]];
        }
        return answers;
    }
};