class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>lastpos;
        int i=0, n =s.size();
        int maxLen = 0;
        for(int j=0;j<n;j++) {
            if(lastpos.count(s[j])) {
                i=max(lastpos[s[j]]+1,i);
            }
            lastpos[s[j]]=j;
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};
