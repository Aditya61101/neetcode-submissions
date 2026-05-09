class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(char c:tasks) freq[c-'A']+=1;
        
        priority_queue<int>pq;
        for(int f:freq) if(f!=0) pq.push(f);
        
        int time=0;
        while(pq.size()) {
            // since any alphabet should appear after n cycles, next round starts after n iterations
            int cycles=n+1;
            vector<int>resting;
            while(cycles--) {
                if(pq.size()) {
                    int f=pq.top(); pq.pop();
                    time+=1;
                    f-=1;
                    if(f>0) resting.push_back(f);
                } else if(resting.size()) {
                    time+=1;
                }
                else break;
            }
            for(int f:resting) {
                pq.push(f);
            }
        }
        return time;
    }
};
