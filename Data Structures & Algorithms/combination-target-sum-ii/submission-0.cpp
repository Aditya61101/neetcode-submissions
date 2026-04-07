class Solution {
private:
    void solve(int st, vector<int>& c, int tar, vector<int>& t, vector<vector<int>>& r) {
        if(tar==0) {
            r.push_back(t);
            return;
        }
        for(int i=st; i<c.size(); i++) {
            if(i>st && c[i]==c[i-1]) continue; // we ignore duplicate value at same level
            if(c[i]>tar) break; // we don't need to go ahead in this loop
            t.push_back(c[i]);
            solve(i+1, c, tar-c[i], t, r);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res; vector<int>temp;
        solve(0, candidates, target, temp, res);
        return res;
    }
};
