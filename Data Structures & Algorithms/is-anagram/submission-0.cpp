class Solution {
public:
    bool isAnagram(string s, string t) {
        int ls = s.length(), lt = t.length();
        if(ls!=lt) return false;
        
        vector<int>alpha(26);
        for(int i=0;i<ls;i++) {
            alpha[s[i]-'a']+=1;
        }

        for(int i=0;i<lt;i++) {
            alpha[t[i]-'a']-=1;
        }

        for(int i=0;i<26;i++) if(alpha[i]!=0) return false;

        return true;
    }
};
