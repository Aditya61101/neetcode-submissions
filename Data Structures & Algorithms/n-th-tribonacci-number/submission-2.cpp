class Solution {
    vector<int>dp;
    int solve(int i) {
        if(i==0) return 0;
        if(i==1||i==2) return 1;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=solve(i-1)+solve(i-2)+solve(i-3);
    }
public:
    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return solve(n);
    }
};