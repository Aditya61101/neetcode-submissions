// dp[i]: no. of ways to decode a string starting from i
class Solution {
    int n;
public:
    int numDecodings(string s) {
        n = s.length();
        int p1=1, p2=0;
        for(int i=n-1;i>=0;i--) {
            int curr=0;
            if(s[i]=='0') curr=0;
            else {
                curr=p1;
                if(i+1<n && (s[i]=='1' || s[i]=='2' && s[i+1]<'7')) curr+=p2;
            }
            p2=p1;
            p1=curr;
        }
        return p1;
        // return solve(s,0,dp);
    }
};
