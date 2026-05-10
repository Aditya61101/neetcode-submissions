class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.emplace(a,'a'); 
        if(b>0) pq.emplace(b,'b'); 
        if(c>0) pq.emplace(c,'c');

        string str="";
        while(pq.size()>=2) {
            auto [f1,c1]=pq.top(); pq.pop();
            auto [f2,c2]=pq.top(); pq.pop();
            
            str+=c1; f1-=1;
            if(f1>0 && (str.size()<2 || str[str.size()-2]!=c1)) { str+=c1; f1-=1; }

            str+=c2; f2-=1;
            // if(f2>0) { str+=c2; f2-=1; }

            if(f1>0) pq.emplace(f1,c1);
            if(f2>0) pq.emplace(f2,c2);
        }

        if(pq.size()) {
            auto [f,c]=pq.top(); pq.pop();
            str+=c; f-=1;
            if(f>0) str+=c;
        }

        return str;
    }
};