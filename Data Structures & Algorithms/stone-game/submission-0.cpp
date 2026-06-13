// minmx approach
class Solution {
    vector<vector<int>>dp;
    int solve(int l, int r, vector<int>&piles) {
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        // alice takes from front
        int takeFromFront = piles[l]+min(solve(l+2,r,piles),solve(l+1,r-1,piles));
        // alice takes from end
        int takeFromEnd = piles[r]+min(solve(l+1,r-1,piles),solve(l,r-2,piles));
        return dp[l][r]=max(takeFromFront,takeFromEnd);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(),piles.end(),0);
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        int aliceScore = solve(0,n-1,piles);
        int bobScore = total - aliceScore;
        return aliceScore > bobScore;
    }
};