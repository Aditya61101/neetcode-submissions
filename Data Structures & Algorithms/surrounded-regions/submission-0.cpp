class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<int>dr={0,0,-1,1}, dc={1,-1,0,0};
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        for(int r=0;r<rows;r++) {
            if(r!=0 && r!=rows-1) {
                if(board[r][0]=='O') { q.push({r,0}); vis[r][0]=true; }
                if(board[r][cols-1]=='O') { q.push({r,cols-1}); vis[r][cols-1]=true; }
            } else {
                for(int c=0;c<cols;c++) if(board[r][c]=='O') {q.push({r,c}); vis[r][c]=true; }
            }
        }
        while(q.size()) {
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nr=r+dr[i], nc=c+dc[i];
                if(nr<0 || nr==rows || nc<0 || nc==cols || vis[nr][nc] || board[nr][nc]=='X') {
                    continue;
                }
                q.push({nr,nc});
                vis[nr][nc]=true;
            }
        }

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) if(board[r][c]=='O' && !vis[r][c]) board[r][c]='X';
        }
    }
};
