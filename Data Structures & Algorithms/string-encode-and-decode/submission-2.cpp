class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(string str:strs) {
            encoded+=to_string(str.size())+'#'+str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        // if(s.empty()) return {};
        vector<string> decodedStrs;
        int i=0, n=s.length();
        while(i<n) {
            int j = i;
            while(s[j]!='#') j+=1;
            // "23" -> 23
            int len = stoi(s.substr(i, j-i));
            decodedStrs.push_back(s.substr(j+1, len));
            // the next starting character of length of next string is at j+len+1 index
            i=j+len+1;
        }
        return decodedStrs;
    }
};
