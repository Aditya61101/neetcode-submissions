class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string name = "";
        for(char c:path) {
            // if(c=='.') dots+=c;
            if(c=='/') {
                if(name==".." && st.size()>0) st.pop();
                else if(name!="" && name!="." && name!="..") st.push(name);
                name="";
            } else {
                name+=c;
            }
        }
        if(name==".." && st.size()>0) st.pop();
        if(name!="" && name!="." && name!="..") st.push(name);
        name="";
        
        vector<string>strs;
        while(st.size()) {
            strs.push_back(st.top());
            st.pop();
        }
        reverse(strs.begin(),strs.end());
        
        string ans = "/";
        for(string &s:strs) {
            ans+=s;
            ans+="/";
        }
        if(ans.length()>1) ans.pop_back();
        return ans;
    }
};