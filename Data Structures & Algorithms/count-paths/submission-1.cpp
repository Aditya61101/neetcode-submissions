// without memoization, T.C:O(2^(m*n))
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
        vector<vector<int>>dp(m,vector<int>(n,0));
        // ways to reach (m-1,n-1) from cells of last column is 1
        for(int i=0;i<m;i++) dp[i][n-1]=1;
        // ways to reach (m-1,n-1) from cells of last row is 1
        for(int j=0;j<n;j++) dp[m-1][j]=1;

        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
        // return solve(0,0,dp);
    }
};
