class Solution {
    int solve(int n,vector<int>&dp) {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        int nums=1e9;
        for(int i=1;i<=n;i++) {
            if(i>n) continue;
            int sqroot = sqrt(i);
            // perfect square check
            if(sqroot*sqroot==i) nums=min(nums,1+solve(n-i,dp));
        }
        return dp[n]=nums;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};