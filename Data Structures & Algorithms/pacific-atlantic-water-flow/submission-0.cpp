class Solution {
    int rows, cols;
    vector<int>dr={0,0,-1,1}, dc={1,-1,0,0};
    
    void bfs(queue<pair<int,int>>&q, vector<vector<int>>&h, vector<vector<bool>>&vis) {
        while(q.size()) {
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nr = r+dr[i], nc=c+dc[i];
                if(nr<0 || nr==rows || nc<0 || nc==cols || h[r][c]>h[nr][nc] || vis[nr][nc]) {
                    continue;
                }
                q.push({nr,nc});
                vis[nr][nc]=true;
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(); 
        cols = heights[0].size();
        vector<vector<bool>>pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>>atlantic(rows, vector<bool>(cols, false));
        // pacific
        queue<pair<int,int>>qp;
        for(int r=0;r<rows;r++) {
            qp.push({r,0});
            pacific[r][0]=true;
        }
        for(int c=0;c<cols;c++) {
            qp.push({0,c}); pacific[0][c]=true;
        }
        bfs(qp,heights,pacific);
        // atlantic
        queue<pair<int,int>>qa;
        for(int r=0;r<rows;r++) {
            qa.push({r,cols-1});
            atlantic[r][cols-1]=true;
        }
        for(int c=0;c<cols;c++) {
            qa.push({rows-1, c});
            atlantic[rows-1][c]=true;
        }
        bfs(qa,heights,atlantic);
        vector<vector<int>>ans;
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(pacific[r][c] && atlantic[r][c]) ans.push_back({r,c});
            }
        }
        return ans;
    }
};
