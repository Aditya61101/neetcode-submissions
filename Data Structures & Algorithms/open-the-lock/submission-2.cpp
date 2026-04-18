class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadSets(deadends.begin(), deadends.end());
        unordered_set<string>visited;
        string src="0000";
        if(deadSets.count(src)) return -1;
        queue<pair<string,int>>q;
        q.push({src,0});
        visited.insert(src);
        while(q.size()) {
            auto [comb, moves] = q.front();
            q.pop();
            if(comb==target) return moves;
            for(int i=0;i<4;i++) {
                char c = comb[i];
                // below loop covers both +1 and -1 case
                for(int j=-1;j<=1;j+=2) {
                    int x = c-'0'; // converting the char to int
                    x+=j;
                    // if before adding, x was 9 and j=1
                    if(x==10) x-=10;
                    // if before adding, x was 0 and j=-1
                    if(x==-1) x+=10;
                    comb[i]=x+'0';
                    if(!visited.count(comb) && !deadSets.count(comb)) {
                        q.push({comb,moves+1});
                        visited.insert(comb);
                    }
                }
                comb[i]=c; // reverting for the next iteration 
            }
        }
        return -1;
    }
};