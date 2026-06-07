// without memoization, T.C:O(2^(m+n))
// with memoization, T.C:O(m*n)
// dp[i][j] -> no. of ways to reach (m-1,n-1) starting from (i,j)
class Solution {
    int rows,cols;
    int solve(int i, int j, vector<vector<int>>&dp) {
        if(i==rows-1 && j==cols-1) return 1;
        // invalid path
        if(i>rows-1 || j>cols-1) return 0;
        // already visited (i,j)
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(i,j+1,dp);
        int down = solve(i+1,j,dp);

        return dp[i][j]=right+down;
    }
public:
    int uniquePaths(int m, int n) {
        rows=m;cols=n;
        vector<int>dp(n,1); // (only one way along the last row).
        // starts from second last col and row
        // since value for last row and col is already filled with 1
        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                dp[j]+=dp[j+1];
            }
        }
        return dp[0];
        // return solve(0,0,dp);
    }
};
