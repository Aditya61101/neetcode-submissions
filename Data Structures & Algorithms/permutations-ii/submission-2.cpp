// using in place swapping and set to avoid duplicate entries at same recursion level
class Solution {
private:
    void solve(int s, vector<vector<int>>&r, vector<int>& n) {
        if(s==n.size()) {
            r.push_back(n); return;
        }
        unordered_set<int>dup;
        for(int i=s;i<n.size();i++) {
            if(dup.count(n[i])) continue;
            dup.insert(n[i]);
            swap(n[i], n[s]);
            solve(s+1, r, n);
            swap(n[i], n[s]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>per;
        vector<bool>vis(nums.size());
        solve(0, res, nums);
        return res;
    }
};