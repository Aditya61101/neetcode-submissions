class Solution {
    int lastSqRoot;
    int solve(int n,vector<int>&dp) {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];

        int nums=1e9;
        for(int i=1;i*i<=n;i++) {
            nums=min(nums,1+solve(n-i*i,dp));
        }
        return dp[n]=nums;
    }
public:
    int numSquares(int n) {
        // memoization
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        
        // tabulation
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        for(int tar=1;tar<=n;tar++) {
            for(int i=1;i*i<=tar;i++) {
                dp[tar]=min(dp[tar],1+dp[tar-i*i]);
            }
        }
        return dp[n];
    }
};