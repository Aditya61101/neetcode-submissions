class Solution {
private:
    bool solve(int x, int y, string &s, vector<vector<char>>& bd, string &w, vector<vector<bool>>&v) {
        if(s==w) return true;
        if(x<0 || x>=bd[0].size()|| y<0 || y>=bd.size() || v[y][x]) return false;
        if(s.length()>w.length() || bd[y][x]!=w[s.length()]) return false;
        s+=bd[y][x];
        v[y][x]=true;
        vector<int> dx={1,-1, 0,0};
        vector<int> dy={0,0,1,-1};
        for(int i=0;i<4;i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(solve(nx, ny, s, bd, w, v)) return true;
        }
        s.pop_back();
        v[y][x]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(), c=board[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        for(int i=0;i<r;i++) {
            string str="";
            for(int j=0;j<c;j++) {
                if (solve(j, i, str, board, word, vis)) return true;
            }
        }
        return false;
    }
};
