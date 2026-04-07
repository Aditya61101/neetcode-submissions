class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minL = INT_MAX;
        for(string &str:strs) {
            minL = min(minL, (int)str.length());
        }
        int i=0;
        while(i<minL) {
            for(int j=1;j<strs.size();j++) {
                if(strs[j-1][i]!=strs[j][i]) return ans;
            }
            ans+=strs[0][i];
            i+=1;
        }
        return ans;
    }
};