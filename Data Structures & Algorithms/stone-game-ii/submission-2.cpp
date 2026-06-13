class Solution {
    int n;
    vector<vector<int>>dp;
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.resize(n+1,vector<int>(n+1,0));
        int totalPts = accumulate(piles.begin(),piles.end(),0);
        // base case
        // for(int M=1;M<=n;M++) dp[n][M]=0;
        for(int i=n-1;i>=0;i--) {
            for(int M=n;M>=1;M--) {
                int wt=0;
                dp[i][M]=-1e9;
                for(int x=1;x<=min(n-i,2*M);x++) {
                    wt+=piles[i+x-1];
                    int diff = wt-dp[i+x][max(x,M)];
                    dp[i][M]=max(diff,dp[i][M]);
                }
            }
        }
        return (totalPts+dp[0][1])/2;
    }
};