class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        unordered_map<char,unordered_set<char>>adj;
        vector<int>allChars(26);
        vector<int>indegree(26);
        for(int i=0;i<n;i++){
            string &curr=words[i];
            for(char c:curr) allChars[c-'a']=1;
            for(int j=i+1;j<n;j++){
                string &next=words[j];
                int k=0;
                bool isEntered=false;
                while(k<min(next.size(),curr.size())){
                    if(curr[k]!=next[k]){
                        auto[_,inserted]=adj[curr[k]].insert(next[k]);
                        if(inserted) indegree[next[k]-'a']+=1;
                        isEntered=true;
                        break;
                    }
                    k+=1;
                }
                // if prefix are present in wrong order
                if(!isEntered && next.size()<curr.size()) return "";
            }
        }
        // for(auto it:adj){
        //     for(char c:it.second) indegree[c-'a']+=1;
        // }
        queue<char>q;
        for(int i=0;i<26;i++) {
            char alphabet=char('a'+i);
            if(allChars[i]==1 && indegree[i]==0) {
                q.push(alphabet);
            }
        }
        unordered_set<char>helper;
        string order="";
        while(q.size()){
            char c=q.front(); q.pop();
            helper.insert(c);
            order+=c;
            for(char v:adj[c]){
                if(--indegree[v-'a']==0) q.push(v);
            }
        }
        for(int it:indegree) if(it!=0) return "";
        // leftover chars: there order doesn't matter
        for(int i=0;i<26;i++){
            char alphabet=char('a'+i);
            if(allChars[i]==1 && !helper.count(alphabet)) order+=alphabet;
        }
        return order;
    }
};
