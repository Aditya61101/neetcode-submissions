class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int maxLen=0,st=0;
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])) {
                    dp[i][j]=true;
                    if(j-i+1>maxLen) {
                        maxLen=j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxLen);
    }
};
