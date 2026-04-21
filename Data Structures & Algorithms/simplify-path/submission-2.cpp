class Solution {
    void changeDirectory(string &name, stack<string>&st) {
        if(name==".." && st.size()>0) st.pop();
        else if(name!="" && name!="." && name!="..") st.push(name);
        name="";
    }
public:
    string simplifyPath(string path) {
        stack<string>st;
        string name = "";
        for(char c:path) {
            if(c=='/') {
                changeDirectory(name,st);
            } else {
                name+=c;
            }
        }
        changeDirectory(name,st);
        
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