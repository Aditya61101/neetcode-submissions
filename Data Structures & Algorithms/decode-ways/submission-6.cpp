// dp[i]: no. of ways to decode a string starting from i
class Solution {
    int n;
public:
    int numDecodings(string s) {
        n = s.length();
        vector<int>dp(n+1,-1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--) {
            dp[i]=0;
            if(s[i]!='0') {
                dp[i]+=dp[i+1];
                if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))) dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};
