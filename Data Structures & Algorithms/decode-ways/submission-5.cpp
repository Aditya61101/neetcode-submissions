// dp[i]: no. of ways to decode a string starting from i
class Solution {
    int n;
    int solve(string &s, int i, vector<int>&dp) {
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];

        int cnt=0;
        if(s[i]!='0') {
            cnt+=solve(s,i+1,dp);
            if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))) cnt+=solve(s,i+2,dp);
        }
        return dp[i]=cnt;
    }
public:
    int numDecodings(string s) {
        n = s.length();
        vector<int>dp(n+1,-1);
        // dp[n]=1;
        // for(int i=n-1;i>=0;i--) {
        //     dp[i]=0;
        //     for(int j=i;j<min(i+2,n);j++) {
        //         string str = s.substr(i,j-i+1);
        //         if(str[0]=='0' || stoi(str)>26) break;
        //         dp[i]+=dp[j+1];
        //     }
        // }
        // return dp[0];
        return solve(s,0,dp);
    }
};
