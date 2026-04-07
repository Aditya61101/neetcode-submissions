class Solution {
private:
    bool solve(int x, int y, int idx, vector<vector<char>>& bd, string &w, vector<vector<bool>>&v) {
        if(idx==w.length()) return true;
        if(x<0 || x>=bd[0].size()|| y<0 || y>=bd.size() || v[y][x] || bd[y][x]!=w[idx]) return false;
        v[y][x]=true;
        vector<int> dx={1,-1, 0,0};
        vector<int> dy={0,0,1,-1};
        for(int i=0;i<4;i++) {
            if(solve(x+dx[i], y+dy[i], idx+1, bd, w, v)) return true;
        }
        v[y][x]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(), c=board[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if (solve(j, i, 0, board, word, vis)) return true;
            }
        }
        return false;
    }
};
