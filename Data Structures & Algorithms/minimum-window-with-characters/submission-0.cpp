class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        int required = t.length();
        int i=0, minLen=INT_MAX, st=0;
        unordered_map<char,int>freq;
        for(char c: t) freq[c]++;

        for(int j=0;j<s.length();j++) {
            if(freq[s[j]]>0) required--;
            freq[s[j]]--;
            while(required==0) {
                if(minLen > j-i+1) {
                    st=i; minLen=j-i+1;
                }
                if(freq[s[i]]>=0) required++;
                freq[s[i]]++;
                i++;
            }
        }
        // cout<<st<<" "<<minLen<<"\n";
        if(minLen==INT_MAX) return "";
        return s.substr(st, minLen);
    }
};
