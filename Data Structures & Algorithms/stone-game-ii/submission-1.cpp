class Solution {
    int n;
    vector<vector<int>>dp;
    int solve(int i, int M, vector<int>&piles) {
        if(i==n) return 0;
        if(dp[i][M]!=-1e9) return dp[i][M];
        
        int wt=0, maxD=-1e9;
        for(int x=1;x<=min(n-i,2*M);x++) {
            wt+=piles[i+x-1];
            int diff = wt-solve(i+x,max(x,M),piles);
            maxD=max(diff,maxD);
        }
        return dp[i][M]=maxD;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.resize(n,vector<int>(n+1,-1e9));
        int totalPts = accumulate(piles.begin(),piles.end(),0);
        int maxDiff = solve(0,1,piles);
        cout<<maxDiff<<"\n";
        return (totalPts+maxDiff)/2;
    }
};