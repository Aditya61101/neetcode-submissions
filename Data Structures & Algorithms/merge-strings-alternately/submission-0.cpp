class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int l1=word1.size(), l2=word2.size();
        int i=0, j=0;
        while(i<l1 && j<l2) {
            ans+=word1[i++];
            ans+=word2[j++];
        }
        // for remaining characters
        while(i<l1) ans+=word1[i++];
        while(j<l2) ans+=word2[j++];
        
        return ans;
    }
};