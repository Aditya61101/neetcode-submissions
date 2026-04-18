class Solution {
    unordered_set<string>deadSets;
    vector<string> getNeighbour(string &s) {
        vector<string>neighbours;
        for(int i=0;i<4;i++) {
            char c = s[i];
            // below loop covers both +1 and -1 case
            for(int j=-1;j<=1;j+=2) {
                int x = c-'0'; // converting the char to int
                x+=j;
                // if before adding, x was 9 and j=1
                if(x==10) x-=10;
                // if before adding, x was 0 and j=-1
                if(x==-1) x+=10;
                s[i]=x+'0';
                neighbours.push_back(s);
            }
            s[i]=c; // reverting for the next iteration 
        }
        return neighbours;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        for(string d:deadends) deadSets.insert(d);
        
        string src="0000";
        if(deadSets.count(src)) return -1;
        
        unordered_set<string>front{src}, back{target}, visited{src,target};
        int steps=0;
        while(front.size() && back.size()) {
            // we always want to expand/explore the smaller size
            if(front.size() > back.size()) {
                swap(front,back);
            }
            unordered_set<string>next;
            for(string curr:front) {
                for(string &neighbour:getNeighbour(curr)) {
                    if(back.count(neighbour)) return steps+1;
                    if(!visited.count(neighbour) && !deadSets.count(neighbour)) {
                        visited.insert(neighbour);
                        next.insert(neighbour);
                    }
                }
            }
            front = next;
            steps+=1;
        }
        return -1;
    }
};