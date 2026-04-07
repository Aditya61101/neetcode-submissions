// visited map
class Solution {
private:
    void solve(vector<int>&n, unordered_map<int, bool>&v, vector<vector<int>>&r, vector<int>&p) {
        if(p.size()==n.size()) {
            r.push_back(p); return;
        }
        for(int i=0;i<n.size();i++) {
            if(v[n[i]]) continue;
            v[n[i]]=true;
            p.push_back(n[i]);
            solve(n, v, r, p);
            v[n[i]]=false;
            p.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>per;
        unordered_map<int, bool>mp;
        for(auto &e:nums) mp[e]=false;
        solve(nums, mp, res, per);
        return res;
    }
};
