class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26);
        for(char c:s) freq[c-'a']+=1;

        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++) if(freq[i]!=0) pq.push({freq[i],i});
        
        string organized="";
        while(pq.size()) {
            vector<pair<int,int>>remaining;
            int cycles = 2;
            while(cycles>0) {
                if(pq.size()) {
                    auto [f,i] = pq.top(); pq.pop();
                    organized+=char(i+'a');
                    if(--f>0) remaining.emplace_back(f,i);
                } else if(remaining.size()) return "";
                else break;
                cycles-=1;
            }
            for(auto p:remaining) pq.emplace(p);
        }
        return organized;
    }
};