// using visited array for index
class Solution {
private:
    void solve(vector<vector<int>>&r, vector<int>&p, vector<bool>&v, vector<int>& n) {
        if(p.size()==n.size()) {
            r.push_back(p); return;
        }
        for(int i=0;i<n.size();i++) {
            if(v[i]) continue;
            if(i>0 && n[i]==n[i-1] && !v[i-1]) continue;
            p.push_back(n[i]);
            v[i]=true;
            solve(r, p, v, n);
            p.pop_back();
            v[i]=false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>per;
        vector<bool>vis(nums.size());
        solve(res, per, vis, nums);
        return res;
    }
};