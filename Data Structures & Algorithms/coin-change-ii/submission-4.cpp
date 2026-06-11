class Solution {
    // dp[i][amount] -> no. of ways to achieve amount starting from i
    int n;
    vector<vector<int>>dp;
    int solve(int i, int amount, vector<int>&coins) {
        if(amount==0) return 1;
        if(i==n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int take = 0;
        if(amount>=coins[i]) take=solve(i,amount-coins[i],coins);
        int nottake = solve(i+1,amount,coins);
        
        return dp[i][amount]=take+nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};
