class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int>mp;
        int i=0, len=0, max_f=0;
        for(int j=0;j<n;j++) {
            mp[s[j]]++;
            max_f = max(max_f, mp[s[j]]);
            while((j-i+1) - max_f > k) {
                mp[s[i]]-=1;
                i+=1;
                // max_f = 0;
                // for(auto const& [key, val] : mp) max_f = max(max_f, val);
            }
            len = max(len, j-i+1);
        }
        return len;
    }
};
