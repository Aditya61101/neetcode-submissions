class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>dep(numCourses);
        vector<vector<int>>adjList(numCourses);
        for(auto pre:prerequisites) {
            dep[pre[0]]+=1;
            adjList[pre[1]].push_back(pre[0]);
        }
        queue<int>validCourses;
        for(int i=0;i<dep.size();i++) if(dep[i]==0) validCourses.push(i);

        vector<int>orders;
        while(validCourses.size()) {
            int currCourse = validCourses.front();
            validCourses.pop();
            orders.push_back(currCourse);
            for(int incomingCourse: adjList[currCourse]) {
                if(--dep[incomingCourse]==0) validCourses.push(incomingCourse);
            }
        }
        if(orders.size()!=numCourses) return {};
        return orders;
    }
};
