class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        while(!q.empty()){
            auto [y, x] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ny=dy[i]+y, nx=dx[i]+x;
                if(ny>=0 && ny<r && nx>=0 && nx<c && grid[ny][nx]==INT_MAX) {
                    grid[ny][nx]=grid[y][x]+1;
                    q.push({ny, nx});
                }
            }
        }
    }
};
