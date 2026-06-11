class Solution {
    // dp[i][amount] -> no. of ways to achieve amount starting from i
    int n;
    vector<vector<int>>dp;
    int solve(int i, int amount, vector<int>&coins) {
        if(amount==0) return 1;
        if(i==n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];

        int cnt=0;
        // to avoid permutation i.e [1,2,1] [1,1,2] since they are same combination
        // we always move ahead instead of starting from beginning
        for(int j=i;j<n;j++) {
            if(amount>=coins[j]) cnt+=solve(j,amount-coins[j],coins);
        }
        return dp[i][amount]=cnt;
    }
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.resize(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        
        for(int i=n-1;i>=0;i--) {
            for(int amt=0;amt<=amount;amt++) {
                for(int j=i;j<n;j++) {
                    if(amt>=coins[j]) dp[i][amt]+=dp[j][amt-coins[j]];
                }
            }
        }
        return dp[0][amount];
        // return solve(0,amount,coins);
    }
};
