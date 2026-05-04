class Solution {
    // dp[i] represents min cost to reach n starting from i
    // T.C: O(n), S.C: O(n)
    vector<int>dp;
    int n;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n+1,-1);
        dp[n]=0;
        dp[n-1]=cost[n-1];
        for(int i=n-2;i>=0;i--) {
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        
        return min(dp[0],dp[1]);
    }
};
