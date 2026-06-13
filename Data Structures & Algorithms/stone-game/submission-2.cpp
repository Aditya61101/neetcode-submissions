// score difference approach (alice-bob)
class Solution {
    vector<vector<int>>dp;
    int solve(int l, int r, vector<int>&piles) {
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        // alice takes from front
        int takeFromFront = piles[l]-solve(l+1,r,piles);
        // alice takes from end
        int takeFromEnd = piles[r]-solve(l,r-1,piles);
        return dp[l][r]=max(takeFromFront,takeFromEnd);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n+1,vector<int>(n,0));

        for(int l=n-1;l>=0;l--) {
            for(int r=0;r<n;r++) {
                // alice takes from front
                int takeFromFront = piles[l]-dp[l+1][r];
                // alice takes from end
                int takeFromEnd = piles[r]-(r>0 ? dp[l][r-1]: 0);
                return dp[l][r]=max(takeFromFront,takeFromEnd);
            }
        }
        return dp[0][n-1]>0;
    }
};