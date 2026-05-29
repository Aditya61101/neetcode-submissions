class Solution {
    int solve(int n, vector<int>&dp) {
        // n=1,2,3,4:2*2=4
        if(n<=4) return n;
        if(dp[n]!=0) return dp[n];

        int maxValue = 0;
        for(int i=1;i<n;i++) {
            maxValue = max(maxValue,i*solve(n-i,dp));
        }
        return dp[n]=maxValue;
    }
public:
    int integerBreak(int n) {
        if(n<=2) return 1;
        if(n==3) return 2;
        vector<int>dp(n+1,0);
        for(int i=2;i<=4;i++) dp[i]=i;
        // dp[2]=2; dp[3]=3; dp[4]=4;
        for(int v=5;v<=n;v++) {
            for(int i=1;i<v;i++) {
                dp[v]=max(dp[v],i*dp[v-i]);
            }
        }
        return dp[n];
        // return solve(n,dp);
    }
};