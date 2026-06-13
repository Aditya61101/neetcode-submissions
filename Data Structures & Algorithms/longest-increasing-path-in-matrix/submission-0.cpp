class Solution {
    vector<int>dr={0,0,-1,1}, dc={1,-1,0,0};
    vector<vector<int>>dp;
    int rows,cols;
    int solve(int r, int c, vector<vector<int>>& m) {
        if(dp[r][c]!=0) return dp[r][c];
        
        int len=1;
        for(int i=0;i<4;i++) {
            int nr=r+dr[i], nc=c+dc[i];
            if(nr<0 || nr>=rows || nc<0 || nc>=cols) continue;
            if(m[nr][nc] > m[r][c]) {
                len=max(len,1+solve(nr,nc,m));
            }
        }
        return dp[r][c]=len;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows=matrix.size(),cols=matrix[0].size();
        dp.resize(rows,vector<int>(cols,0));
        int maxLen=1;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                int len=solve(i,j,matrix);
                maxLen=max(len,maxLen);
            }
        }
        return maxLen;
    }
};
