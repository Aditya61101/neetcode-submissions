// score difference approach (alice-bob)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        // dp.resize(n+1,vector<int>(n,0));
        vector<int>dp(n,0);
        for(int l=n-1;l>=0;l--) {
            for(int r=0;r<n;r++) {
                // alice takes from front
                int takeFromFront = piles[l]-dp[r];
                // alice takes from end
                int takeFromEnd = piles[r]-(r>0 ? dp[r-1]: 0);
                return dp[r]=max(takeFromFront,takeFromEnd);
            }
        }
        return dp[n-1]>0;
    }
};