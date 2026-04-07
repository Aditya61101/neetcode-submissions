class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dd(deadends.begin(), deadends.end());
        if (dd.count("0000")) return -1;
        if (dd.count(target)) return -1;
        if (target == "0000") return 0;
        unordered_set<string> start = {"0000"};
        unordered_set<string> end = {target};
        unordered_set<string> visited_start = {"0000"};
        unordered_set<string> visited_end = {target};
        int steps=0;
        while(!end.empty() && !start.empty()) {
            if(start.size()>end.size()){
                swap(start, end);
                swap(visited_start, visited_end);
            } 
            
            unordered_set<string>nextLvl;
            for(const string &curr:start) {
                for(int i=0;i<4;i++) {
                    for(int d=-1;d<=1;d+=2) {
                        string next=curr;
                        next[i]=(curr[i] - '0' + d + 10) % 10 + '0';
                        // if(vs.count(next) || dd.count(next)) continue;
                        // if(end.count(next)) return steps+1;
                        // nextLvl.insert(next);
                        // vs.insert(next);
                        if (dd.count(next)) continue;
                        if (visited_end.count(next)) return steps + 1;
                        if (visited_start.count(next)) continue;

                        visited_start.insert(next);
                        nextLvl.insert(next);
                    }
                }
            }
            start=nextLvl;
            steps++;
        }
        return -1;
    }
};