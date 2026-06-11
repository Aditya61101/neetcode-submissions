class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int i=n-1;i>=0;i--) {
            // reuse allowed, so current coin must see its own updates.
            // hence forward iteration
            for(int amt=coins[i]; amt<=amount; amt++) {
                dp[amt]+=dp[amt-coins[i]];
            }
        }
        return dp[amount];
    }
};
