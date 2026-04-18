class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols=grid[0].size();
        int freshFruitCounts=0;
        // {r,c,time}
        queue<tuple<int,int,int>>q;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++) {
                if(grid[r][c]==2) q.push({r,c,0});
                if(grid[r][c]==1) freshFruitCounts+=1;
            }
        }
        vector<int>dr={-1,1,0,0}, dc={0,0,-1,1};
        int time=0;
        while(q.size()) {
            auto [r,c,t] = q.front();
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i], nc=c+dc[i];
                if(nr<0 || nr==rows || nc<0 || nc==cols || grid[nr][nc]!=1) continue;
                grid[nr][nc]=2;
                freshFruitCounts-=1;
                q.push({nr,nc,t+1});
            }
        }
        if(freshFruitCounts==0) return time;
        return -1;
    }
};
