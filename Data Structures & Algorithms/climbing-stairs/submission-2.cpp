// tabulation -> bottom-up approach
class Solution {
    // dp[i] stores no. of ways to reach the top starting from i
    vector<int>dp;
public:
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        dp[n]=1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--) {
            dp[i]=dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
};
