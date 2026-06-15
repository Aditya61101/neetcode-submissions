class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int l=n-1;l>=0;l--) {
            for(int r=0;r<n;r++) {
                // for loop gives the choices
                for(int k=l;k<=r;k++) {
                    // consider nums[k] as the last balloon to be burst in the range [l,r]
                    // this means all balloons except kth balloon are already burst in this range.
                    // so the nearest unburst balloon on left and on right of k lies at (l-1)th,(r+1)th index.
                    int coins = nums[k]*(l>0 ? nums[l-1] : 1)*(r<n-1 ? nums[r+1] : 1);
                    
                    int leftScore = 0, rightScore=0;
                    // since in memoization we return 0 if(l>r)
                    if(l<=k-1) leftScore = dp[l][k-1];
                    if(k+1<=r) rightScore = dp[k+1][r];
                    
                    int totalScore = leftScore+rightScore+coins;
                    
                    dp[l][r]=max(dp[l][r],totalScore);
                }
            }
        }
        return dp[0][n-1];
    }
};
