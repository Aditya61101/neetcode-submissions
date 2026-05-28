class Solution {
    int lastSqRoot;
    int solve(int n,vector<int>&dp) {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];

        int nums=1e9;
        for(int i=1;i<=lastSqRoot;i++) {
            int sq = i*i;
            if(sq>n) continue;
            nums=min(nums,1+solve(n-sq,dp));
        }
        return dp[n]=nums;
    }
public:
    int numSquares(int n) {
        lastSqRoot=sqrt(n);
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};