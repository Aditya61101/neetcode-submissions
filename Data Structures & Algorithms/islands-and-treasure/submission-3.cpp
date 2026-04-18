class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), cols=grid[0].size();
        // stores {i,j,dist}
        queue<tuple<int,int,int>>q;
        // this helps in starting our traversal from treasure chest
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) if(grid[r][c]==0) {
                q.push({r,c,0});
            }
        }
        vector<int>dr={-1,1,0,0}, dc={0,0,-1,1};
        while(q.size()) {
            auto [r,c,d] = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nr = r+dr[i], nc = c+dc[i];
                if(nr<0 || nr==rows || nc<0 || nc==cols || grid[nr][nc]==-1 || grid[nr][nc]!=INT_MAX) {
                    continue;
                }
                grid[nr][nc]=d+1;
                q.push({nr,nc,d+1});
            }
        }
    }
};
