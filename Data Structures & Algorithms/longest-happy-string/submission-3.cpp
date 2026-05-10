class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.emplace(a,'a'); 
        if(b>0) pq.emplace(b,'b'); 
        if(c>0) pq.emplace(c,'c');

        string str="";
        while(pq.size()) {
            auto [f1,c1]=pq.top(); pq.pop();
            int n = str.size();
            // if last two chars were same as current most frequent char
            // we dont append it
            if(n>=2 && str[n-1]==c1 && str[n-2]==c1) {
                // if no next frequent char is there
                if(pq.empty()) return str;
                auto [f2,c2]=pq.top(); pq.pop();
                str+=c2; f2-=1;
                if(f2>0) pq.emplace(f2,c2);
                // push most frequent char again in heap
                pq.emplace(f1,c1);
            } else {
                str+=c1; f1-=1;
                if(f1>0) pq.emplace(f1,c1);
            }
        }
        return str;
    }
};