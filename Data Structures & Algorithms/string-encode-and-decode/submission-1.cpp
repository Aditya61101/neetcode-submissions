class Solution {
    unordered_set<int>deLimiterIdx;
public:
    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        int cnt = 0;
        string encoded = "";
        for(string str:strs) {
            encoded+=str;
            encoded+=',';
            deLimiterIdx.insert(cnt+str.length());
            cnt+=str.length()+1;
        }
        // encoded.pop_back();
        return encoded;
    }

    vector<string> decode(string s) {
        // cout<<s<<"\n";
        if(s.empty()) return {};
        s.pop_back();
        vector<string> decodedStrs;
        string temp = "";
        for(int i=0;i<s.length();i++) {
            if(s[i]==',' && deLimiterIdx.count(i)) {
                decodedStrs.push_back(temp);
                temp="";
            } else {
                temp+=s[i];
            }
        }
        decodedStrs.push_back(temp);
        return decodedStrs;
    }
};
