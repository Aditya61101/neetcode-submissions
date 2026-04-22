class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        string str="", num="";
        for(char c:s) {
            if(c>='0' && c<='9') {
                if(str!="") st.push(str);
                str="";
                num+=c;
            }
            else if(c>='a' && c<='z') str+=c;
            else if(c=='['){
                if(str!="") st.push(str);
                st.push(num);
                num="";
                str="";
            } else {
                if(str!="") st.push(str);
                str="";
                vector<string>temp;
                // pop till we dont get any freq
                while(st.size() && isalpha(st.top()[0])) {
                    temp.push_back(st.top());
                    st.pop();
                }
                int freq=1;
                if(st.size()) {freq=stoi(st.top()); st.pop();}
                reverse(temp.begin(), temp.end());
                string tempStr="";
                for(string &t:temp) tempStr+=t;
                string t="";
                while(freq--) {
                    t+=tempStr;
                }
                st.push(t);
                t=""; tempStr="";
            }
        }
        if(str!="") st.push(str);
        str="";

        vector<string>tempV;
        while(st.size()) {
            tempV.push_back(st.top());
            st.pop();
        }
        reverse(tempV.begin(),tempV.end());
        string ans="";
        for(string &s:tempV) ans+=s;
        return ans;
    }
};