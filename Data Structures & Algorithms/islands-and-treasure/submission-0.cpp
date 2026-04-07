class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>>v(r, vector<int>(c,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    v[i][j]=1;
                }
            }
        }
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        while(!q.empty()){
            auto [co, d]=q.front();
            auto [y, x] = co;
            q.pop();
            for(int i=0;i<4;i++){
                int ny=dy[i]+y, nx=dx[i]+x;
                if(ny>=0 && ny<r && nx>=0 && nx<c && v[ny][nx]==0 && grid[ny][nx]!=-1) {
                    grid[ny][nx]=d+1;
                    q.push({{ny, nx}, d+1});
                    v[ny][nx]=1;
                }
            }
        }
    }
};
