class Solution {
private:
    bool solve(int i, int t, vector<int>& m, vector<int>& sq) {
        if(i==m.size()) {
            bool areEq = all_of(sq.begin(), sq.end(), [&](int x) { return x == sq[0]; });
            return areEq;
        }
        for(auto &s:sq){
            if(m[i]+s<=t){
                s+=m[i];
                if(solve(i+1, t, m, sq)) return true;
                s-=m[i];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4!=0) return false;
        int tar = sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int>sq(4,0);
        return solve(0, tar, matchsticks, sq);
    }
};