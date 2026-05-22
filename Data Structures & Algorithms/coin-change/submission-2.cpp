// dp[amount] -> min. no. of ways to achieve the amount
class Solution {
    vector<int>dp;
    int solve(vector<int>& coins, int amount) {
        // nothing to reduce, a correct path, hence return 0
        if(amount==0) return 0;
        // a wrong path, should not be considered
        // hence return INT_MAX
        if(amount<0) return INT_MAX;
        
        if(dp[amount]!=-1) return dp[amount];
        
        int minWays = INT_MAX;
        // for(int j=i;j<n;j++) -> solve(coins, amount-coin, i+1)
        // could use above loop as well, but then for memoization
        // we need to maintain 2D DP.
        for(int coin:coins) {
            int response = solve(coins, amount-coin);
            // postorder calculations
            if(response==INT_MAX) continue;
            minWays = min(minWays, 1+response);
        }
        return dp[amount]=minWays;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // tabulation
        dp.resize(amount+1,INT_MAX);
        dp[0]=0;
        for(int currAmount=1; currAmount<amount+1; currAmount++) {
            for(int coin:coins) {
                if(coin > currAmount || dp[currAmount-coin]==INT_MAX) continue;
                dp[currAmount] = min(dp[currAmount],1+dp[currAmount-coin]);
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
        
        // // memoization
        // dp.resize(amount+1,-1);
        // int response = solve(coins,amount);
        // // if response remains INT_MAX,
        // // then its not possible to achieve the amount through any path
        // return response==INT_MAX ? -1: response; 
    }
};
