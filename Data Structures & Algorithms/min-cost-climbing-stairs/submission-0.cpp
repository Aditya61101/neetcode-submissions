class Solution {
    // dp[i] represents min cost to reach n starting from i
    vector<int>dp;
    int n;
    int solve(int i, vector<int>&cost) {
        if(i==n) return 0;
        if(i>n) return 1e9;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(solve(i+1,cost), solve(i+2,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n+1,-1);
        return min(solve(0,cost),solve(1,cost));
    }
};
