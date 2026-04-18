class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>dependencies(numCourses);
        vector<vector<int>>adjList(numCourses);
        for(auto pre: prerequisites) {
            dependencies[pre[0]]+=1;
            // pre[1] is done then go and do pre[0]
            adjList[pre[1]].push_back(pre[0]);
        }
        queue<int>coveredCourses;
        for(int i=0;i<numCourses;i++) {
            if(dependencies[i]==0) coveredCourses.push(i);
        }

        while(coveredCourses.size()) {
            int course = coveredCourses.front();
            coveredCourses.pop();
            for(int incomingCourse: adjList[course]) {
                dependencies[incomingCourse]--;
                // there's no dependency left hence this course can be attended
                if(dependencies[incomingCourse]==0) {
                    coveredCourses.push(incomingCourse);
                }
            }
        }
        for(int dependency:dependencies) if(dependency!=0) return false;
        return true;
    }
};
