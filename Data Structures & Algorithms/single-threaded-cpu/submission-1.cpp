class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>sortedTasks;
        for(int i=0;i<tasks.size();i++) {
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>order;
        int i=0, n=sortedTasks.size(), time = sortedTasks[0][0];
        while(i<n) {
            if(time<sortedTasks[i][0]) time=sortedTasks[i][0];
            // enqueue logic: if enqueue time is less than or equal to current time
            // then we enqueue those tasks
            while(i<n && sortedTasks[i][0]<=time) {
                pq.push({sortedTasks[i][1], sortedTasks[i][2]});
                i+=1;
            }
            if(pq.size()) {
                order.push_back(pq.top()[1]);
                time+=pq.top()[0];
                pq.pop();
            }
        }
        while(pq.size()) {
            order.push_back(pq.top()[1]);
            time+=pq.top()[0];
            pq.pop();
        }
        return order;
    }
};