class Solution {
    // dp[i][amount] -> no. of ways to achieve amount starting from i
    int n;
    vector<vector<int>>dp;
    int solve(int i, int amount, vector<int>&coins) {
        if(amount==0) return 1;
        if(i==n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];

        int cnt=0;
        for(int j=i;j<n;j++) {
            if(amount>=coins[j]) cnt+=solve(j,amount-coins[j],coins);
        }
        return dp[i][amount]=cnt;
    }
public:
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};
