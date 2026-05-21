class Solution {
    int solve(string &s, int i, vector<int>&dp) {
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];

        int cnt=0;
        for(int j=i; j<min(i+2,(int)s.length()); j++) {
            string str = s.substr(i,j-i+1);
            // cout<<str<<" "<<j+1<<"\n";
            if(str[0]=='0' || stoi(str) > 26) break;
            cnt+=solve(s,j+1,dp);
            // cout<<cnt<<"\n";
        }
        return dp[i]=cnt;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return solve(s,0,dp);
    }
};
